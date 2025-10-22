#ifndef SHAPES
#define SHAPES

#include <stdio.h> //pour utiliser le type FILE (manipulation de fichiers).
#include <stdlib.h> //pour malloc, free, etc.
#include "color.h" // our utiliser la structure color_t

typedef struct shape_s shape_t;  //Elle informe le compilateur qu’il existera une structure nommée shape_s, qu’on appellera ensuite simplement shape_t.

typedef void (*shape_save_func)(shape_t* instance, FILE* file);

typedef struct shape_s 
{
    void* shape; // bunun sayesinde tüm şekilleri kullanabiliriz,  elle peut aussi contenir des données spécifiques à chaque type de forme.
    /*
    Pour un cercle (circle_t) → cx, cy, r.

    Pour un carré (square_t) → x, y, width.

    Pour un rectangle (rect_t) → x, y, width, height.

    Chaque structure spécifique est placée dans le champ shape du shape_t.
    */
    
    
    color_t fillColor;
    color_t strokeColor;
    int strokeWidth;

    shape_save_func saveFunc;
    // LINKED LIST
    shape_t* next;
} shape_t;

void shape_free(shape_t* instance);

#endif
