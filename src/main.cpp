#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GameObj.h"
#include "Game.h"


int SCREEN_W = 800;
int SCREEN_H = 600;

int FPS = 60;


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    

    GLFWwindow* window = glfwCreateWindow(800, 600, "Teste", NULL, NULL);
    if(window == NULL){
        std::cout << "Erro ao criar janela" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    gladLoadGL();

    glViewport(0, 0, 800, 600);

    GLfloat color1[3] = {1.0f, 1.0f, 1.0f};
    GLfloat color2[3] = {1.0f, 0.0f, 1.0f};
    GLfloat color3[3] = {1.0f, 0.0f, 0.0f};

    GameObj objects[5] = {
        {0.5f, 0.5f, 0.01f, 0.2f, 0, color1, GL_QUADS},
        {-0.5f, 0.0f, 0.01f, 0.2f, 0, color2, GL_QUADS},
        {0.8f, -0.5f, 0.01f, 0.2f, 0, color3, GL_QUADS},
        {-0.8f, -0.5f, 0.01f, 0.2f, 1, color3, GL_QUADS},
        {0.0f, 0.0f, 0.01f, 0.4f, 0, color1, GL_LINES},
    };

    Game game = {window, objects, 5};

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        game.Draw();
        game.Update();

        glFlush();
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    
    glfwTerminate();

    return 0;
}
