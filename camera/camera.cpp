#include "camera.h"
#include <math.h>

//-----------------------------------------------------------------------------
Camera::Camera()
{
    x_pos = 0;   y_pos = 0;   z_pos = 0;
    x_rot = 0;   y_rot = 0;   z_rot = 0;

    setDefaultView(x_pos, y_pos, z_pos, x_rot, y_rot, z_rot);

    mode = EGO;
}

//-----------------------------------------------------------------------------
Camera::Camera(double xpos, double ypos, double zpos, unsigned int mode)
{
    Camera::x_pos = xpos; Camera::y_pos = ypos; Camera::z_pos = zpos;
    Camera::x_rot = 0.0f; Camera::y_rot = 0.0f; Camera::z_rot = 0.0f;
    Camera::mode = mode;
    setDefaultView(x_pos, y_pos, z_pos, x_rot, y_rot, z_rot);
}

//-----------------------------------------------------------------------------
Camera::Camera(double xpos, double ypos, double zpos, double xrot, double yrot, double zrot, unsigned int mode)
{
    Camera::x_pos = xpos; Camera::y_pos = ypos; Camera::z_pos = zpos;
    Camera::x_rot = xrot; Camera::y_rot = yrot; Camera::z_rot = zrot;
    setDefaultView(x_pos, y_pos, z_pos, x_rot, y_rot, z_rot);
    Camera::mode = mode;
}

//-----------------------------------------------------------------------------
void Camera::look()
{
    if( mode == OBJECT ) glTranslatef(x_pos, y_pos, z_pos);
    glRotatef(x_rot, 1.0f, 0.0f, 0.0f );
    glRotatef(z_rot, 0.0f, 0.0f, 1.0f );
    glRotatef(360.0f-y_rot, 0.0f, 1.0f, 0.0f );
    if( mode == EGO ) glTranslatef(x_pos, y_pos, z_pos);
}

//-----------------------------------------------------------------------------
void Camera::setMode(unsigned int m)
{
    mode = m;
}

//-----------------------------------------------------------------------------
unsigned int Camera::getMode()
{
    return mode;
}

//-----------------------------------------------------------------------------
void Camera::move_NS(float s)
{
    if( mode == EGO )
    {
        x_pos += (float)sin(y_rot*M_PI/180)*s;
        z_pos += (float)cos(y_rot*M_PI/180)*s;
    }
    else if( mode = OBJECT )
    {
        z_pos += s;
    }
}

//-----------------------------------------------------------------------------
void Camera::move_OW(float s)
{
    if( mode == EGO )
    {
        x_pos += (float)sin((y_rot+90.0f)*M_PI/180)*s;
        z_pos += (float)cos((y_rot+90.0f)*M_PI/180)*s;
    }
    else if( mode = OBJECT )
    {
        x_pos += s;
    }
}

//-----------------------------------------------------------------------------
void Camera::move_UD(float s)
{
    y_pos += s;
}

//-----------------------------------------------------------------------------
void Camera::move_NS_UD(float s)
{
    if( mode == EGO )
    {
        x_pos += (float)sin((y_rot)*M_PI/180)*s;
        y_pos += (float)sin((x_rot)*M_PI/180)*s;
        z_pos += (float)cos((y_rot)*M_PI/180)*s;
    }
    else if( mode = OBJECT )
    {
        x_pos += s;
        y_pos += s;
    }
}

//-----------------------------------------------------------------------------
void Camera::rotate_NS(float s)
{
    // TODO...
    if( mode == EGO )
    {
        z_rot += s;    
    }
    else if( mode = OBJECT )
    {
        z_rot += s;
    }
}

//-----------------------------------------------------------------------------
void Camera::rotate_OW(float s)
{
    y_rot += s;
}

//-----------------------------------------------------------------------------
void Camera::rotate_UD(float s)
{
    x_rot += s;
}

//-----------------------------------------------------------------------------
void Camera::rotate_Y_aroundPoint(float s, float r, float x, float y, float z )
{
    x_pos += sin(2.0f*M_PI/s)*r;
    z_pos += cos(2.0f*M_PI/s)*r;

    positionCamera(x_pos,y_pos,z_pos,x,y,z);
}

//-----------------------------------------------------------------------------
double Camera::xpos()
{
    return x_pos;
}

//-----------------------------------------------------------------------------
double Camera::ypos()
{
    return y_pos;
}

//-----------------------------------------------------------------------------
double Camera::zpos()
{
    return z_pos;
}

//-----------------------------------------------------------------------------
double Camera::xrot()
{
    return x_rot;
}

//-----------------------------------------------------------------------------
double Camera::yrot()
{
    return y_rot;
}

//-----------------------------------------------------------------------------
double Camera::zrot()
{
    return z_rot;
}

//-----------------------------------------------------------------------------
void Camera::defaultView()
{
    x_pos = x_pos_d;    y_pos = y_pos_d;    z_pos = z_pos_d;
    x_rot = x_rot_d;    y_rot = y_rot_d;    z_rot = z_rot_d;
}

//-----------------------------------------------------------------------------
void Camera::setDefaultView(double xpos, double ypos, double zpos, double xrot, double yrot, double zrot)
{
    x_pos_d = xpos; y_pos_d = ypos; z_pos_d = zpos;
    x_rot_d = xrot; y_rot_d = yrot; z_rot_d = zrot;
}

//-----------------------------------------------------------------------------
void Camera::positionCamera(float xpos, float ypos, float zpos, float xeye, float yeye, float zeye)
{
    x_pos = xpos;   y_pos = ypos;   z_pos = zpos;

    double a,b,c,alpha = 90;

    if( a != 0)
    {
        y_rot = asin((yeye/sqrt((yeye*yeye)+(xeye*xeye))));
        y_rot *= 180/M_PI; // Back to babylon
        y_rot = 90 - alpha;
    }

    if( b < 0 ) y_rot *= -1;
}
