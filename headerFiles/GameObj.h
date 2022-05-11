#ifndef GAME_OBJ_CLASS_H
#define GAME_OBJ_CLASS_H

#include "glad/glad.h"

class GameObj{

    public:
        GLfloat x;
        GLfloat y;
        GLfloat size;
        GLenum type;

        GameObj(GLfloat x, GLfloat y, GLfloat size, GLenum type);
        GameObj();
        void Draw();

};

#endif