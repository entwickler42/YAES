#include "world.h"

//-----------------------------------------------------------------------------
World::World(TOpenGLAPPanel* s) : GLObject(s)
{
    needs_update = true;
}

//-----------------------------------------------------------------------------
World::~World()
{}

//-----------------------------------------------------------------------------
void World::repaint()
{
    for(unsigned int i=0;i<sector_v.size();i++) sector_v[i].paint();
}

//-----------------------------------------------------------------------------
int World::load(const char* f)
{
    ifstream* in = new ifstream(f);
    if(!*in) return -1;

    // loat the header

    string line;
    char   name[256];

    line = readLine(in);
    sscanf(line.c_str(),"SECTORS: %i",&sectors);
    line = readLine(in);
    sscanf(line.c_str(),"TEXTURES_DEFINITION: %s",&name);

    // load the textures
    tm.load(name);

    // load the sectors
    Sector sector(Surface(),&tm);

    while( !in->eof() && sector.size() != sectors )
    {
        sector.load(in);
        sector_v.push_back(sector);
    }

    return 0;
}

//-----------------------------------------------------------------------------
void World::setFilter(unsigned int filter)
{
    for(unsigned int i=0;i<sector_v.size();i++)
    {
        sector_v[i].filter = filter;
        sector_v[i].needs_update = true;
    }
    needs_update = true;
}

//-----------------------------------------------------------------------------
unsigned int World::getFilter()
{
    if( sector_v.size() > 0 ) return sector_v[0].filter;

    return 0;
}

