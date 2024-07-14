#include <iostream>
#include <vector>

using std::vector;

struct Vertex {
    Vertex() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    Vertex(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    float x, y, z;
};

struct Vertices {
    Vertices() {
        this->vertices = vector<Vertex>();
        numVertices = 0;
    }

    Vertices(Vertex vertices[]) {
        this->vertices = vector<Vertex>(vertices, vertices + sizeof(vertices) / sizeof(vertices[0]));
        numVertices = sizeof(vertices);
    }
    
    int numVertices;
    vector<Vertex> vertices;
};

class Object {
    private:
        Vertices vertices;
    public:
        Object(Vertices verts) {};
};

class Triangle : Object {
    private:
        Vertices vertices;
    public:

};