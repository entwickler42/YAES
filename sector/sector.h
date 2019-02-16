#ifndef SECTOR_H
#define SECTOR_H

#include "../texture2d/texturemap.h"
#include "../texture2d/texture2d.h"
#include "../globject/globject.h"

class Sector : public GLObject
{
    public:
        Sector(TOpenGLAPPanel* s,TextureMap* tm );
        ~Sector();

        virtual void repaint();

        bool load(ifstream* in);
        bool save(ofstream* out);
        unsigned int size();
        TRIANGLE* at(unsigned int i);

        unsigned int filter;

    private:
        TextureMap* tm;
        unsigned int triangles;
        TRIANGLE*    triangle;
};

#endif
