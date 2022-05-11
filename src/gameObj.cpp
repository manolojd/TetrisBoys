#include "GameObj.h"

GameObj::GameObj(GLfloat x, GLfloat y, GLfloat size, GLenum type){
    this->x = x;
    this->y = y;
    this->size = size;

    this->type = type;
}

GameObj::GameObj(){}

void GameObj::Draw(){

    // Só vai funcionar para quadrados...
    glPushMatrix();
        glBegin(this->type);
            glColor3f(1.0f, 0.3f, 0.3f);
            glVertex2f(this->x, this->y);
            glVertex2f(this->x + this->size, this->y);
            glVertex2f(this->x + this->size, this->y + this->size);
            glVertex2f(this->x, this->y + this->size);
        glEnd();
    glPopMatrix();
}