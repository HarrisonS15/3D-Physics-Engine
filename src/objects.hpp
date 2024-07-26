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

        Vertex(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Vertex getMidPoint(Vertex v2) {
            return Vertex((x + v2.x)/2, (y + v2.y)/2, (z + v2.z)/2);
        }

        float getX() {
            return x;
        }

        float getY() {
            return y;
        }

        float getZ() {
            return z;
        }

        void setX(float x) {
            this->x = x;
        }

        void setY(float y) {
            this->y = y;
        }

        void setZ(float z) {
            this->z = z;
        }

        void setAll(float x, float y, float z)  {
            this->x = x;
            this->y = y;
            this->z = z;
        }

    private:
        float x, y, z;
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

        void setVertexA(float x, float y, float z) {
            a = Vertex(x,y,z);
        }

        void setVertexB(Vertex b) {
            this->b = b;
        }

        void setVertexB(float x, float y, float z) {
            b = Vertex(x,y,z);
        }

        float getLength() {
            return calcLength();
        }
    
    private:
        Vertex a, b;

        float calcLength() {
            return sqrt(float((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY()- b.getY()) * (a.getY() - b.getY()) + (a.getZ() - b.getZ()) * (a.getZ() - b.getZ())));
        }
};

class Object2D {
    
    protected:
        vector<Vertex> vertices;
        vector<Line> sides;
        void setSides() {
            sides = vector<Line>(vertices.size());
            for (int a = 0; a < vertices.size(); a++) {
                int b = (a == vertices.size() - 1 ) ? 0 : a+1 ;
                sides[a] = Line(vertices[a], vertices[b]);
            }
        }
    public:
        Object2D(vector<Vertex> vertices) : vertices(vertices) {}
        Object2D() {};

        float calcArea() {};

        int getNumVertices() {
            return vertices.size();
        }

        Vertex getCentroid() {

            float x, y, z;
            x = y = z = 0;
            for (int i = 0; i < vertices.size(); i++) {
                x += vertices[i].getX();
                y += vertices[i].getY();
                z += vertices[i].getZ();
            }
            return Vertex(x/vertices.size(), y/vertices.size(), z/vertices.size());
        }

        float* getVerticesAsArray() {
            float* verticesArr = new float[vertices.size()*3];
            for (int i = 0; i < vertices.size(); i++) {
                int index = i*3;
                verticesArr[index] = vertices[i].getX();
                verticesArr[index+1] = vertices[i].getY();
                verticesArr[index+2] = vertices[i].getZ();
            }
            return verticesArr;
        }
};

class Triangle : public Object2D {
    
    protected:

    public:
        /// @brief 
        /// @param vertices 
        Triangle(vector<Vertex> vertices) {
            try {
                if (vertices.size() != 3) {throw VerticeException();}
                this->vertices = vertices;
                setSides();
            } catch (VerticeException ve) {
                std::cout << ve.what() << std::endl;
            }
        }

        Triangle(Vertex v1, Vertex v2, Vertex v3) {
            this->vertices = vector<Vertex>{v1, v2, v3};
            setSides();
        }

        Triangle() {
            this->vertices = vector<Vertex>{Vertex(-1,1,-1), Vertex(1,1,-1), Vertex(0,-2,2)};
            setSides();
        }

        float calcArea() {
            // vertices[0].x;
            // 0.5*abs(vertices[0].x*(vertices[1].y));
            return 0;
        }


};
#endif