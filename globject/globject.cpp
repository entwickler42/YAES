#include "globject.h"
#include <fstream>

//-----------------------------------------------------------------------------
GLObject::GLObject(TOpenGLAPPanel* s)
{
    surface         = s;
    needs_update    = true;
}

//-----------------------------------------------------------------------------
GLObject::~GLObject()
{}

//-----------------------------------------------------------------------------
TOpenGLAPPanel* GLObject::Surface()
{
    return surface;
}

//-----------------------------------------------------------------------------
void GLObject::paint()
{
    if(needs_update)
    {
        needs_update = false;
        display_list = glGenLists(1);
        glNewList(display_list,GL_COMPILE);
            repaint();
        glEndList();
    }

    glCallList(display_list);
}

//-----------------------------------------------------------------------------
void GLObject::repaint()
{}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const string readLine(ifstream* in)
{
    string line;
    char ch;

    do
    {
        line = "";
        do
        {
            in->read(&ch,1);
            line.push_back(ch);
        }while( ch != '\n' && !in->eof());
    } while((((line[0] == '/') && (line[1] == '/')) || line[0] == '\n') && !in->eof());

    return line;
}

