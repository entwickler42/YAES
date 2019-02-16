#ifndef TYPES_H
#define TYPES_H

#include <vector.h>

typedef struct _VERTEX
{
    float x,y,z;
    float u,v;
} VERTEX;

typedef struct _TRIANGLE
{
    VERTEX vertex[3];
    int texture_id;
} TRIANGLE;

#endif
