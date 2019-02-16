#ifndef MOUSECAMERA_H
#define MOUSECAMERA_H

#include <windows.h>
#include "camera.h"

class MouseCamera : public Camera
{
    friend class Camera;

    public:
        MouseCamera();
        ~MouseCamera();

        void rotate_Y_aroundPoint(float s, int X, int Y );

        void onMove(int x, int y);
        void onDown(int x, int y,TMouseButton b);
        void onUp  (int x, int y,TMouseButton b);

    private:
        TMouseButton button;
        POINT cursor_down;
        POINT cursor_move;
        int move_x, move_y, down_y, down_x, up_x, up_y;
        int move_x_o, move_y_o, down_y_o, down_x_o, up_x_o, up_y_o;

        void setOld(int x, int y, int &ox, int &oy);

};

#endif
 
