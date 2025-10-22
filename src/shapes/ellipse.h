#ifndef ELLIPSE
#define ELLIPSE

#include "shapes.h"

typedef struct ellipse_s 
{
    int rx, ry;
    int cx, cy;
} ellipse_t;

shape_t* ellipse_create(color_t fillColor, color_t strokeColor, int strokeWidth, int cx, int cy, int rx, int ry);
void ellipse_save(shape_t* instance, FILE* file);

#endif