#ifndef GAME_OBJ_CLASS_H
#define GAME_OBJ_CLASS_H

#include "glad/glad.h"

class GameObj{

    public:
        GLfloat x;
        GLfloat y;
        GLfloat size;
        GLenum type;
        GLfloat angle;
        GLfloat color[3];
        int walkable;
        GLfloat scale;
        GLfloat velocity;
        GLfloat rotation;
        int tValue;

        GameObj(GLfloat x, GLfloat y, GLfloat velocity, GLfloat size, int tValue, GLfloat color[3], GLenum type);
        GameObj();
        void Draw();
        void setWalkable(int bValue);
        void setScale(GLfloat scale);
        void setRotation(GLfloat rotation);
        

};

#endif