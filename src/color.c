#include "color.h"

void color_fprint(color_t* color, FILE* file) //void → Fonksiyon geriye değer döndürmez, sadece işlem yapar.
{
    fprintf(file, "#%02x%02x%02x", color->r, color->g, color->b); // 
}

//color_t* color → Yazdırılacak rengin bilgisini tutan pointer
//FILE*  -Rengi yazacağımız dosya pointer’ı. 
//fprintf → Dosyaya yazmak için kullanılan standart C fonksiyonu.


//Fonksiyon bir color_t nesnesini alıyor.

//Rengin RGB değerlerini hex formatına çevirip SVG dosyasına yazıyor.

//Geri değer yok, sadece dosya üzerinde işlem yapıyor.