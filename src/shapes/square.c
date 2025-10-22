#include "square.h"

// kare oluşturma function

shape_t* square_create(color_t fillColor, color_t strokeColor, int strokeWidth, int x, int y, int w)
{
    square_t *shape = malloc(sizeof(square_t));
    if (shape == NULL) return NULL;
    
    shape->x = x; 
    shape->y = y; 
    shape->w = w;
  
    shape_t* wrapper = malloc(sizeof(shape_t));
    if (wrapper == NULL) 
    {
        free(shape); 
        return NULL;
    }

    wrapper->shape = shape;
    wrapper->fillColor = fillColor;
    wrapper->strokeColor = strokeColor;
    wrapper->strokeWidth = strokeWidth;
    wrapper->saveFunc = &square_save;
    return wrapper;
}

void square_save(shape_t* instance, FILE* file)
{
    square_t* s = (square_t*)instance->shape;
    fprintf(file, "<rect x=\"%i\" y=\"%i\" width=\"%i\" height=\"%i\" stroke-width=\"%i\" fill=\"", s->x, s->y, s->w, s->w, instance->strokeWidth);
    color_fprint(&instance->fillColor, file);
    fprintf(file, "\" stroke=\"");
    color_fprint(&instance->strokeColor, file);
    fprintf(file, "\" />");
}