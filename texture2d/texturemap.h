#ifndef TEXTUREMAP_H
#define TEXTUREMAP_H

#include "texture2d.h"
#include <vector>

class TextureMap
{
    public:
        TextureMap();
        ~TextureMap();

        void bindTexture(unsigned int i, unsigned int filter);
        const Texture2D& operator [] (unsigned int i);
        bool load(const char* f);

    private:
        vector<Texture2D> texture_v;

};

#endif
