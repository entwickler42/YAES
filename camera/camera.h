#ifndef CAMERA_H
#define CAMERA_H

#include "TOpenGLAPPanel.h"

enum { EGO, OBJECT };

class Camera
{
    public:
        Camera();
        Camera(double xpos, double ypos, double zpos, unsigned int mode);
        Camera(double xpos, double ypos, double zpos, double xrot, double yrot, double zrot, unsigned int mode);

        void setMode(unsigned int m);
        unsigned int getMode();

        void look();

        virtual void defaultView();
        void setDefaultView(double xpos, double ypos, double zpos, double xrot, double yrot, double zrot);

        void move_NS(float s);
        void move_OW(float s);
        void move_UD(float s);

        void move_NS_UD(float s);

        void rotate_NS(float s);
        void rotate_OW(float s);
        void rotate_UD(float s);

        void positionCamera(float xpos, float ypos, float zpos, float xeye, float yeye, float zeye);

        void rotate_Y_aroundPoint(float s, float r, float x, float y, float z );

        double xpos();
        double ypos();
        double zpos();

        double xrot();
        double yrot();
        double zrot();

    private:
        unsigned int mode;

        double x_pos, y_pos, z_pos;
        double x_rot, y_rot, z_rot;

        double x_pos_d, y_pos_d, z_pos_d;
        double x_rot_d, y_rot_d, z_rot_d;

};

#endif
