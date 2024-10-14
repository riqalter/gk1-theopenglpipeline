#include <GL/glew.h>  
#include <GLFW/glfw3.h>  
#include <iostream>  

using namespace std;  

void init(GLFWwindow* window) {  
    // Initialize any settings for the OpenGL context here if needed  
}  

void display(GLFWwindow* window, double currentTime) {  
    glClearColor(0.0, 0.0, 0.0, 0.1); // Set clear color to BLACK  
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer  
}  

int main(void) {  
    if (!glfwInit()) {  
        exit(EXIT_FAILURE);  
    }  

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  

    GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter 2 - Program 1", NULL, NULL);  
    if (!window) {  
        glfwTerminate();  
        exit(EXIT_FAILURE);  
    }  
    
    glfwMakeContextCurrent(window);  
    
    if (glewInit() != GLEW_OK) {  
        glfwTerminate();  
        exit(EXIT_FAILURE);  
    }  

    glfwSwapInterval(1);  
    init(window);  

    // Main loop  
    while (!glfwWindowShouldClose(window)) {  
        display(window, glfwGetTime());  
        glfwSwapBuffers(window);  
        glfwPollEvents();  
    }  

    // Clean up  
    glfwDestroyWindow(window);  
    glfwTerminate();  

    return EXIT_SUCCESS; // Ensure the program returns successfully  
}