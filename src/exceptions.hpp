#include <iostream>

class VerticeException : public std::exception {
    public:
char * what () {
        // to do: make this say what threw it
        return "Wrong number of vertices for shape.";
    }
};