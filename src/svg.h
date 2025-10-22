#ifndef SVG
#define SVG

#include "shapes.h" //shapes.h → Projedeki tüm şekil yapıları ve fonksiyonlarını içerir (circle_t, rect_t, square_t,
#include <stdbool.h> //stdbool.h → C’de bool tipini kullanmamızı sağlar (true/false değerleri).

typedef struct svg_s  
{
    const char* fileName;  //fileName → Kaydedilecek SVG dosyasının adı.
    int width;
    int height;
    shape_t* head;         //head ve tail → Eklenen şekillerin bağlı listesi. Liste boşsa head = tail = NULL.
    shape_t* tail;
} svg_t;

svg_t* svg_new(const char* fileName, int width, int height); //Bellekte yeni bir svg_t nesnesi oluşturur.
// svg_t* svg_read(const char* fileName)

void svg_add(svg_t* instance, shape_t* shape); //Mevcut SVG nesnesine bir shape_t ekler.
bool svg_is_empty(svg_t* instance);            //Eğer head == NULL ise true döner, aksi halde false.

void svg_save(svg_t* instance); //Bellekteki tüm şekilleri SVG formatında dosyaya yazar.

void svg_free(svg_t* instance); //Bellekten şekilleri siler

#endif

//head:Listenin ilk elemanı. Liste boşsa NULL.
//tail:Listenin son elemanı. Yeni şekil eklerken tail üzerinden listeye ekleme yapılır.
//!: 
