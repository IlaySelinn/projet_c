#ifndef SQUARE
#define SQUARE

#include "shapes.h"

typedef struct square_s 
{
    int x, y;
    int w;
} square_t;

shape_t* square_create(color_t fillColor, color_t strokeColor, int strokeWidth, int x, int y, int w);
void square_save(shape_t* instance, FILE* file);

#endif