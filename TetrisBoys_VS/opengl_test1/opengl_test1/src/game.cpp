#include <iostream>
#include "Game.h"

Game::Game(GLFWwindow* window, GameObj objects[], int objCount) {
    this->window = window;
    this->running = 1;
    this->objects = new GameObj[objCount];

    for (int i = 0; i < objCount; i++) {
        this->objects[i] = objects[i];
    }

    GLfloat color[3] = { 0.0f, 1.0f, 0.0f };
    this->player = GameObj{ 0.0f, 0.0f, 0.0f, 0.3f, 0, color, GL_TRIANGLES };
    this->player.setWalkable(1);
}

void Game::Draw() {
    this->player.Draw();
    for (int i = 0; i < sizeof(this->objects); i++) {
        this->objects[i].Draw();
    }
}

void Game::Update() {
    this->processInput();
    for (int i = 0; i < sizeof(this->objects); i++) {
        if (this->objects[i].x + this->objects[i].size >= 1 || this->objects[i].x <= -1) {
            this->objects[i].velocity *= -1;
        }
        this->objects[i].x += this->objects[i].velocity;

    }
}

void Game::processInput() {
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->window, true);
    }

    if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS && this->player.y < 1) {
        this->player.y += 0.01f;
    }

    if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS && this->player.x - this->player.size > -1) {
        this->player.x -= 0.01f;
    }

    if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS && this->player.x < 1 - this->player.size) {
        this->player.x += 0.01f;
    }

    if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS && this->player.y - this->player.size > -1) {
        this->player.y -= 0.01f;
    }

    if (glfwGetKey(this->window, GLFW_KEY_1) == GLFW_PRESS) {
        this->player.setScale(this->player.scale + 0.1f);
    }

    if (glfwGetKey(this->window, GLFW_KEY_2) == GLFW_PRESS) {
        this->player.setScale(this->player.scale - 0.1f);
    }

    if (glfwGetKey(this->window, GLFW_KEY_3) == GLFW_PRESS) {
        if (this->player.rotation == 0) {
            this->player.setRotation(180.0f);
        }
        else {
            this->player.setRotation(0.0f);
        }
    }

    if (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS) {
        this->player.x = 0.0f;
        this->player.y = 0.0f;
    }


}