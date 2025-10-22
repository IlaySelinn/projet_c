#ifndef RECTANGLE
#define RECTANGLE

#include "shapes.h"

typedef struct rectangle_s 
{
    int x, y;
    int width, height;
} rectangle_t;

shape_t* rect_create(color_t fillColor, color_t strokeColor, int strokeWidth, int x, int y, int w, int h);
void rect_save(shape_t* instance, FILE* file);

#endif


//koordinatların sısrası önemli!!!!!!!