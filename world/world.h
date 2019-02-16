#ifndef WORLD_H
#define WORLD_H

#include "../sector/sector.h"

class World : public GLObject
{
    public:
        World(TOpenGLAPPanel* s);
        ~World();

        virtual void repaint();

        int load(const char* f);
        void setFilter(unsigned int filter);
        unsigned int getFilter();

    private:
        unsigned int sectors;
        vector<Sector> sector_v;
        TextureMap tm;
};

#endif
 