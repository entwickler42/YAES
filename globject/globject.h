#ifndef GLOBJECT_H
#define GLOBJECT_H

#include "TOpenGLAPPanel.h"
#include "../include/types.h"
#include <fstream>
#include <string>

class GLObject
{
    public:
        GLObject(TOpenGLAPPanel* s);
        ~GLObject();

        void paint();
        virtual void repaint();
        TOpenGLAPPanel* Surface();

        bool needs_update;
        
     private:
        GLuint  display_list;
        TOpenGLAPPanel* surface;
};

const string readLine(ifstream *in);

#endif

