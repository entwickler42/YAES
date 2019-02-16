#include "sector.h"

//-----------------------------------------------------------------------------
Sector::Sector(TOpenGLAPPanel* s, TextureMap* tm ) : GLObject(s)
{
    Sector::tm      = tm;
    Sector::filter  = 2;
    triangle        = NULL;
}

//-----------------------------------------------------------------------------
Sector::~Sector()
{                                                                   
    if(triangle) delete [] triangle;
}

//-----------------------------------------------------------------------------
bool Sector::load(ifstream* in)
{
    string line;

    triangles = 0;

    if(!*in) return false;

    // Number of triangles in sector ....
    while(triangles == 0 && !in->eof())
    {
        line = readLine(in);
        sscanf(line.c_str(),"TRIANGLES: %i",&triangles);
    }

    // Dim. Sector

    if(triangle) delete [] triangle;
    triangle = new TRIANGLE[triangles];

    // Triangles
    for(unsigned int i=0;i<triangles; i++ )
        for(unsigned int j=0; j<3; j++ )
        {
            float x,y,z,u,v;
            int id = 0;

            line = readLine(in);
            sscanf(line.c_str(),"%f %f %f %f %f %i", &x, &y, &z, &u, &v, &id);

            triangle[i].vertex[j].x = x;
            triangle[i].vertex[j].y = y;
            triangle[i].vertex[j].z = z;
            triangle[i].vertex[j].u = u;
            triangle[i].vertex[j].v = v;
            triangle[i].texture_id = id;
        }

    return true;
}

//-----------------------------------------------------------------------------
bool Sector::save(ofstream* out)
{
    return false;
}

//-----------------------------------------------------------------------------
unsigned int Sector::size()
{
    return triangles;
}

//-----------------------------------------------------------------------------
void Sector::repaint()
{
    glEnable(GL_TEXTURE_2D);
    for(unsigned int i=0;i<triangles;i++)
    {
        tm->bindTexture(triangle[i].texture_id, filter);

        glBegin(GL_TRIANGLES);
            glNormal3f( 0.0f, 0.0f, 1.0f);
    	    glTexCoord2f(triangle[i].vertex[0].u,triangle[i].vertex[0].v);
            glVertex3f(triangle[i].vertex[0].x,triangle[i].vertex[0].y,triangle[i].vertex[0].z);

		    glTexCoord2f(triangle[i].vertex[1].u,triangle[i].vertex[1].v);
            glVertex3f(triangle[i].vertex[1].x,triangle[i].vertex[1].y,triangle[i].vertex[1].z);

        	glTexCoord2f(triangle[i].vertex[2].u,triangle[i].vertex[2].v);
            glVertex3f(triangle[i].vertex[2].x,triangle[i].vertex[2].y,triangle[i].vertex[2].z);
        glEnd();
    }
    glDisable(GL_TEXTURE_2D);
}
