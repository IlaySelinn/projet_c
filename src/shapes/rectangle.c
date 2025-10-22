#include "rectangle.h"

shape_t* rect_create(color_t fillColor, color_t strokeColor, int strokeWidth, int x, int y, int w, int h)
{
    rectangle_t *shape = malloc(sizeof(rectangle_t));
    if (shape == NULL) return NULL;
    
    shape->x = x; 
    shape->y = y; 
    shape->width = w;
    shape->height = h;
  
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
    wrapper->saveFunc = &rect_save;
    return wrapper;
}

void rect_save(shape_t* instance, FILE* file)
{
    rectangle_t* r = (rectangle_t*)instance->shape;
    fprintf(file, "<rect x=\"%i\" y=\"%i\" width=\"%i\" height=\"%i\" stroke-width=\"%i\" fill=\"", r->x, r->y, r->width, r->height, instance->strokeWidth);
    color_fprint(&instance->fillColor, file);
    fprintf(file, "\" stroke=\"");
    color_fprint(&instance->strokeColor, file);
    fprintf(file, "\" />");
}