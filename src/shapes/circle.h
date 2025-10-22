#ifndef CIRCLE // include guard
#define CIRCLE //Amaç: Aynı dosyanın birden fazla kez eklenmesini önlemek.

#include "shapes.h" // diğer şekil tiplerini ve ortak shape_t yapısını kullanmak için shapes.h’i dahil ediyor.

typedef struct circle_s  // typedef sayesinde struct circle_s yerine direkt circle_t diyebiliyoruz.

                         //Sunumda :“circle_t, dairenin bütün özelliklerini tutan küçük bir veri kutusu.”
{
    int cx, cy; 
    int r; // rayon
} circle_t;

shape_t* circle_create(color_t fillColor, color_t strokeColor, int strokeWidth, int cx, int cy, int r); // Daire oluşturur ve bilgileri bir wrapper (shape_t) içine koyar.
void circle_save(shape_t* instance, FILE* file);   //SVG dosyasına daireyi kaydeder.
                                                
#endif 