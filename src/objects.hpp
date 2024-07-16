#include <iostream>
#include <vector>
#include <math.h>

using std::vector;

struct Vertex {
    double x, y, z;
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
    
};

struct Line {
    public:
        Vertex a, b;
        double length;
        Line() {

        } 
        Line(Vertex a, Vertex b) {
            this->a = a;
            this->b = b;
            length = calcLength();
        }
    
    private:
        double calcLength() {
            return sqrt(double((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z)));
        }
};

class Object {
    private:
        vector<Vertex> vertices;
    public:
        Object(Vertex vertices[]) {};
        Object() {};
};

class Triangle : Object {
    private:
        vector<Vertex> vertices;
        vector<Line> lines;
        Vertex midPoint;
        
        
    public:
        Triangle(Vertex vertices[]) {
            this->vertices = vector<Vertex>(vertices, vertices + sizeof(vertices) / sizeof(vertices[0]));

        }
        Triangle() {
            vertices = {Vertex(0, 0, 0), Vertex(1, 1, 0), Vertex(2, 2, 0)};
        }
        float calcArea() {
            // vertices[0].x;
            // 0.5*abs(vertices[0].x*(vertices[1].y));
            return 0;
        }


};