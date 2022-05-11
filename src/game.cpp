#include <iostream>
#include "Game.h"

Game::Game(GLFWwindow* window, GameObj objects[]){
    this->window = window;
    this->running = 1;
    this->objects = objects;
    this->player = GameObj {0.0f, 0.0f, 0.5f, GL_QUADS};
}

void Game::Draw(){

    this->player.Draw();

    for (int i = 0; i < sizeof(this->objects); i++){
        this->objects[i].Draw();
    }
    

}

void Game::Update(){

    this->processInput();

}

void Game::processInput(){
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(this->window, true);
    }

    if(glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS && this->player.y < 1 - this->player.size){
        this->player.y += 0.01f;
    }

    if(glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS && this->player.x > -1){
        this->player.x -= 0.01f;
    }

    if(glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS && this->player.x < 1 - this->player.size){
        this->player.x += 0.01f;
    }

    if(glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS && this->player.y > -1){
        this->player.y -= 0.01f;
    }
    

}