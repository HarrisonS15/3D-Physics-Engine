#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std; 

int main()
{

glfwInit();
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

int windowSize_x = 800;
int windowSize_y = 600;

GLFWwindow* window = glfwCreateWindow(windowSize_x, windowSize_y, "Physics Engine", NULL, NULL);
if (window == NULL)
{
std::cout << "Failed to create GLFW window" << std::endl;
glfwTerminate();
return -1;
}
glfwMakeContextCurrent(window);

if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
{
std::cout << "Failed to initialize GLAD" << std::endl;
return -1;
}

glViewport(0, 0, windowSize_x, windowSize_y);



return 0;
}