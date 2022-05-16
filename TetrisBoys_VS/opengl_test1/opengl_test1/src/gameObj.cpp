#include "GameObj.h"
#include <math.h>
#include <iostream>

void animateWalk(GLfloat x, GLfloat y, GLfloat size, GLfloat angle);

GameObj::GameObj(GLfloat x, GLfloat y, GLfloat velocity, GLfloat size, int tValue, GLfloat color[3], GLenum type) {
    this->x = x;
    this->y = y;
    this->size = size;

    this->angle = 0.0f;
    this->type = type;

    this->velocity = velocity;

    this->scale = 1;

    this->tValue = tValue;

    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];

}

GameObj::GameObj() {}

void GameObj::Draw() {
    switch (this->type) {
    case GL_QUADS:
        glPushMatrix();
        glScalef(this->scale, this->scale, 0.0f);
        glBegin(this->type);
        glColor3f(this->color[0], this->color[1], this->color[2]);
        if (this->tValue == 0) {
            glVertex2f(this->x, this->y);
            glVertex2f(this->x + this->size, this->y);
            glVertex2f(this->x + this->size, this->y + this->size);
            glVertex2f(this->x, this->y + this->size);
        }
        else if (this->tValue == 1) {
            glVertex2f(this->x, this->y);
            glVertex2f(this->x + this->size, this->y);
            glVertex2f(this->x, this->y - this->size);
            glColor3f(0.0f, 1.0f, 1.0f);
            glVertex2f(this->x - this->size, this->y - this->size);
        }
        glEnd();
        glPopMatrix();
        break;
    case GL_TRIANGLES:
        if (this->walkable == 1) {
            this->angle += 1.0f;
            if (this->angle > 360) {
                this->angle = 0;
            }
        }
        glPushMatrix();
        // glTranslatef(this->x, this->y, 0.0f);
        glScalef(this->scale, this->scale, 0.0f);
        glRotatef(this->rotation, 0.0f, 0.0f, 1.0f);
        glBegin(this->type);
        glColor3f(this->color[0], this->color[1], this->color[2]);
        glVertex2f(this->x, this->y);
        glVertex2f(this->x + this->size, this->y - this->size);
        glVertex2f(this->x - this->size, this->y - this->size);
        glEnd();
        glPopMatrix();
        animateWalk(this->x - this->size / 2, this->y, 0.1f, this->angle);
        animateWalk(this->x + this->size / 2, this->y, 0.1f, this->angle);

        break;
    case GL_LINES:
        this->angle += 1.0f;
        if (this->angle > 360) {
            this->angle = 0;
        }
        glPushMatrix();
        glRotatef(this->angle, 1.0f, 1.0f, 1.0f);
        glBegin(this->type);
        glColor3f(this->color[0], this->color[1], this->color[2]);
        glVertex2f(this->x, this->y);
        glVertex2f(this->x + this->size, this->y);
        glEnd();
        glPopMatrix();
        break;
    }
}

void GameObj::setWalkable(int bValue) {
    this->walkable = bValue;
}

void animateWalk(GLfloat x, GLfloat y, GLfloat size, GLfloat angle) {
    double pi2 = 2.0 * 3.142;
    glPushMatrix();
    glRotatef(angle, x, y, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(x + (size * cos(i * pi2 / 20)), (y + (size * sin(i * pi2 / 20))));
    }
    glEnd();
    glPopMatrix();

}

void GameObj::setScale(GLfloat scale) {
    this->scale = scale;
}

void GameObj::setRotation(GLfloat rotation) {
    this->rotation = rotation;
}