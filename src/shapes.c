#include "shapes.h"

void shape_free(shape_t* instance) 
{
    free(instance->shape);
    free(instance);
}
