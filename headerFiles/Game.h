#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "GameObj.h"

class Game{

    public:
        int running;
        GLFWwindow* window;
        GameObj* objects;
        GameObj player;

        Game(GLFWwindow* window, GameObj objects[], int objCount);
        void Draw(); // Graficos
        void Update(); // Logica
        void processInput();


};

#endif