#ifndef COLOR
#define COLOR

#include <stdio.h>

// ANSI renk kodları
//  Bu makrolar, terminalde renkli çıktı almak için kullanılır.
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;34m"
#define YELLOW  "\033[1;33m"
#define ORANGE  "\033[38;2;255;165;0m"
#define PURPLE  "\033[38;2;128;0;128m"
#define PINK    "\033[38;2;255;192;203m"
#define BROWN   "\033[38;2;165;42;42m"
#define GRAY    "\033[1;30m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RESET   "\033[0m"

typedef struct color_s // Renk bilgisini depolamak için kullanılır.
{
    unsigned char r, g, b;  
} color_t;                  

void color_fprint(color_t* color, FILE* file); //Rengi SVG dosyasına yazmak için kullanılan fonksiyonun prototipi.


//FILE* file → yazdırılacak dosya pointer’ı.
//color_t* color → yazdırılacak renk.

#endif