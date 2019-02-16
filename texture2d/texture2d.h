#ifndef TEXTURE_H
#define TEXTURE_H

#include <../globject/globject.h>
#include <gl/glaux.h>

class Texture2D
{
    public:
        Texture2D();
        ~Texture2D();

        void bindTexture(unsigned int filter);
        bool load(const char* file);

    private:
        GLuint texture[3];
        AUX_RGBImageRec* loadBMP(const char *f);        
};

#endif
