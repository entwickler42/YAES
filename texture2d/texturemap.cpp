#include "texturemap.h"

//-----------------------------------------------------------------------------
TextureMap::TextureMap()
{}

//-----------------------------------------------------------------------------
TextureMap::~TextureMap()
{}

//-----------------------------------------------------------------------------
const Texture2D& TextureMap::operator [] (unsigned int i)
{
    return texture_v[i];
}

//-----------------------------------------------------------------------------
bool TextureMap::load(const char* f)
{
    ifstream* in = new ifstream(f);
    if(!*in) return false;

    if( texture_v.size() > 0 ) texture_v.clear();

    string line;
    char   name[256];
    Texture2D texture;

    memset(name,0,256);

    while(!in->eof())
    {
        line = readLine(in);
        sscanf(line.c_str(),"%s",name);
        texture.load(name);
        texture_v.push_back(texture);
    }

    in->close();
    delete in;

    return true;
}

//-----------------------------------------------------------------------------
void TextureMap::bindTexture(unsigned int i, unsigned int filter)
{
    texture_v[i].bindTexture(filter);
}

