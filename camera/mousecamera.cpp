#include "mousecamera.h"

//-----------------------------------------------------------------------------
MouseCamera::MouseCamera()
{
    move_x_o = 0.0f; move_y_o = 0.0f;
    down_x_o = 0.0f; down_y_o = 0.0f;
    up_x_o   = 0.0f;   up_y_o = 0.0f;

    button = NULL;
}

//-----------------------------------------------------------------------------
MouseCamera::~MouseCamera()
{}

//-----------------------------------------------------------------------------
void MouseCamera::onMove(int x, int y)
{
    move_x = x; move_y = y;

    if(button)
    {
        GetCursorPos(&cursor_move);

        if( button == mbRight )
        {
            move_NS(( cursor_down.y - cursor_move.y ) / 10.0f );  move_OW(( cursor_down.x - cursor_move.x ) / 10.0f );
        }
        
        if( button == mbMiddle )
        {
            move_NS_UD( ( cursor_down.y - cursor_move.y ) / 10.0f );
        }
        
        SetCursorPos(cursor_down.x,cursor_down.y);        
    }

    setOld(move_x,move_y,move_x_o,move_y_o);
}
//-----------------------------------------------------------------------------
void MouseCamera::onDown(int x, int y, TMouseButton b)
{
    button = b;
    down_x = x; down_y = y;
    GetCursorPos(&cursor_down);

    setOld(down_x,down_y,down_x_o,down_y_o);
}

//-----------------------------------------------------------------------------
void MouseCamera::onUp  (int x, int y, TMouseButton b)
{
    button = NULL;
    up_x = x; up_y = y;

    setOld(up_x,up_y,up_x_o,up_y_o);
}

//-----------------------------------------------------------------------------
void MouseCamera::setOld(int x, int y, int &ox, int &oy)
{
    ox = x; oy = y;
}

//-----------------------------------------------------------------------------
void MouseCamera::rotate_Y_aroundPoint(float s, int X, int Y)
{
    GLdouble x,y,z,model[16],proj[16];
    GLfloat c;
    GLint    view[4];

    glReadPixels (X,Y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &c);

    glGetDoublev  (GL_MODELVIEW_MATRIX, model);
    glGetDoublev  (GL_PROJECTION_MATRIX, proj);
    glGetIntegerv (GL_VIEWPORT, view);

    gluUnProject(X,Y,c,model,proj,view,&x,&y,&z);

    Camera::rotate_Y_aroundPoint(s,2,x,y,z);
}



