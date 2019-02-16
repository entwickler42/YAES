#include "texture2d.h"

//-----------------------------------------------------------------------------
Texture2D::Texture2D()
{}

//-----------------------------------------------------------------------------
Texture2D::~Texture2D()
{}

//-----------------------------------------------------------------------------
void Texture2D::bindTexture(unsigned int filter)
{
    glBindTexture(GL_TEXTURE_2D,texture[filter]);
}

//-----------------------------------------------------------------------------
bool Texture2D::load(const char* file)
{
    bool result = false;

    AUX_RGBImageRec *TextureImage[1];

    memset(TextureImage,0,sizeof(void *)*1);

    if( (TextureImage[0] = loadBMP(file)) != NULL )
    {
        result = true;
        glGenTextures(3, &texture[0]);

		// Create nearest filtered texture
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);

        // Create linear filtered texture
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);

        // Create mipmapped texture
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
    }
    if (TextureImage[0])
    {
        if (TextureImage[0]->data)
        {
            free(TextureImage[0]->data);
        }

        free(TextureImage[0]);
    }

    return result;
}

//-----------------------------------------------------------------------------
AUX_RGBImageRec* Texture2D::loadBMP(const char *f)
{
    ifstream *in = new ifstream(f,ios::binary);
    if(!*in)
    {
        delete in;
        return NULL;
    }
    in->close();
    delete in;
    return auxDIBImageLoad(f);
}
