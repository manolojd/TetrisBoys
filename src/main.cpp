#include <iostream>
#include <fstream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


int SCREEN_W = 800;
int SCREEN_H = 600;

int main(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Teste", NULL, NULL);
    if(window == NULL){
        std::cout << "Erro ao criar janela" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, 800, 600);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 0, 0, 800, 600, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float angle = 0.0f;
    while(!glfwWindowShouldClose(window)){
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        angle = angle + 1.0f;

        if(angle >= 360){
            angle = 0.0f;
        }

        glPushMatrix();
            glRotatef(angle, 1.0f, 0.0f, 0.0f);
            glBegin(GL_TRIANGLES);
                glVertex3f(0.0f, 0.5f, 0.0f);
                glVertex3f(-0.5f, -0.5f, 0.0f);
                glVertex3f(0.5f, -0.5f, 0.0f);
            glEnd();
        glPopMatrix();

        glPushMatrix();
        std::cout << angle << std::endl;
            // glTranslatef(angle, 0.0f, 0.0f);
            glRotatef(angle, 0.0f, 1.0f, 0.0f);
            glBegin(GL_QUADS);
                glVertex3f(-0.8f, -0.4f, 0.0f);
                glColor3f(0.5f, 0.0f, 0.0f);
                glVertex3f(-0.8f, -0.8f, 0.0f);
                glColor3f(1.0f, 1.0f, 1.0f);
                glVertex3f(-0.4f, -0.8f, 0.0f);
                glVertex3f(-0.4f, -0.4f, 0.0f);
            glEnd();
        glPopMatrix();

        glFlush();
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    return 0;
}
