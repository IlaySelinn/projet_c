#include "ellipse.h"

shape_t* ellipse_create(color_t fillColor, color_t strokeColor, int strokeWidth, int cx, int cy, int rx, int ry)
{
    ellipse_t *shape = malloc(sizeof(ellipse_t));
    if (shape == NULL) return NULL;
    
    shape->rx = rx; 
    shape->ry = ry; 
    shape->cx = cx;
    shape->cy = cy;
  
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
    wrapper->saveFunc = &ellipse_save;
    return wrapper;
}

void ellipse_save(shape_t* instance, FILE* file)
{
    ellipse_t* r = (ellipse_t*)instance->shape;
    fprintf(file, "<ellipse cx=\"%i\" cy=\"%i\" rx=\"%i\" ry=\"%i\" stroke-width=\"%i\" fill=\"", r->cx, r->cy, r->rx, r->ry, instance->strokeWidth);
    color_fprint(&instance->fillColor, file);
    fprintf(file, "\" stroke=\"");
    color_fprint(&instance->strokeColor, file);
    fprintf(file, "\" />");
}