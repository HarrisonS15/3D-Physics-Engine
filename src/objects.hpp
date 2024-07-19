#ifndef CUSTOM_OBJECTS_
#define CUSTOM_OBJECTS_

#include <iostream>
#include <vector>
#include <math.h>
#include <exceptions.hpp>

using std::vector;

struct Vertex {
    public:
        
        Vertex() {
            x = 0.0;
            y = 0.0;
            z = 0.0;
        }

        Vertex(double x, double y, double z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Vertex getMidPoint(Vertex v2) {
            return Vertex((x + v2.x)/2, (y + v2.y)/2, (z + v2.z)/2);
        }

        double getX() {
            return x;
        }

        double getY() {
            return y;
        }

        double getZ() {
            return z;
        }

        void setX(double x) {
            this->x = x;
        }

        void setY(double y) {
            this->y = y;
        }

        void setZ(double z) {
            this->z = z;
        }

    private:
        double x, y, z;
};

struct Line {
    public:
        
        Line() {
            a = Vertex(0, 0, 0);
            b = Vertex(0, 0, 0);
        } 

        Line(Vertex a, Vertex b) {
            this->a = a;
            this->b = b;
        }

        Vertex getCenterOfLine() {
            return a.getMidPoint(b);
        }

        Vertex getVertexA() {
            return a;
        }

        Vertex getVertexB() {
            return b;
        }

        void setVertexA(Vertex a) {
            this->a = a;
        }

        void setVertexA(double x, double y, double z) {
            a = Vertex(x,y,z);
        }

        void setVertexB(Vertex b) {
            this->b = b;
        }

        void setVertexB(double x, double y, double z) {
            b = Vertex(x,y,z);
        }

        double getLength() {
            return calcLength();
        }
    
    private:
        Vertex a, b;

        double calcLength() {
            return sqrt(double((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY()- b.getY()) * (a.getY() - b.getY()) + (a.getZ() - b.getZ()) * (a.getZ() - b.getZ())));
        }
};

class Object2D {
    private:
        vector<Vertex> vertices;
    public:
        Object2D(Vertex vertices[]) {};
        Object2D() {};
        double calcArea() {};
        Vertex getCentroid() {
            double x, y, z;
            x = y = z = 0;
            for (int i = 0; i < vertices.size(); i++) {
                x += vertices[i].getX();
                y += vertices[i].getY();
                z += vertices[i].getZ();
            }
            return Vertex(x/vertices.size(), y/vertices.size(), z/vertices.size());
        }
};

class Triangle : Object2D {
    private:
        vector<Vertex> vertices = {Vertex(0, 0, 0), Vertex(1, 1, 0), Vertex(2, 2, 0)};
        vector<Line> sides;
        Vertex midPoint;

        /// @brief to be used in constructor only. (populates the Vector sides)
        void setSides() {
            sides = vector<Line>(vertices.size());
            for (int a = 0; a < vertices.size(); a++) {
                int b = (a == vertices.size() - 1 ) ? 0 : a+1 ;
                sides[a] = Line(vertices[a], vertices[b]);
            }
        }
        
    public:
        /// @brief 
        /// @param vertices 
        Triangle(Vertex vertices[]) {
            try {
                if (sizeof(vertices) != 3) {throw VerticeException();}
                this->vertices = vector<Vertex>(vertices, vertices + sizeof(vertices) / sizeof(vertices[0]));
                setSides();
            } catch (VerticeException ve) {
                std::cout << ve.what() << std::endl;
            }
        }
        Triangle() {
            setSides();
        }

        double calcArea() {
            // vertices[0].x;
            // 0.5*abs(vertices[0].x*(vertices[1].y));
            return 0;
        }


};
#endif