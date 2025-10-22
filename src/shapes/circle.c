#include "circle.h" // circle.h dosyasını dahil eder

shape_t* circle_create(color_t fillColor, color_t strokeColor, int strokeWidth, int cx, int cy, int r) // circle_create function
    //fillColor Dairenin içini dolduracak renk
    //strokeColor Dairenin kenar rengini belirler
    //strokeWidth Kenarın kalınlığı
    // koordinatlar ve yarıçap(r)

{
    circle_t *shape = malloc(sizeof(circle_t));  //sizeof(circle_t): Bellek bloğunun boyutunu circle_t tipi için belirler.
    if (shape == NULL) return NULL;              // Eğer bellek yetmezse malloc NULL döndürür. Bu yüzden hemen kontrol ediyoruz:
                                                 
    shape->cx = cx;  //Dinamik olarak oluşturduğumuz circle_t nesnesinin alanlarına, kullanıcıdan aldığımız değerleri atıyoruz.
    shape->cy = cy;  
    shape->r = r;    
  
    shape_t* wrapper = malloc(sizeof(shape_t)); //shape_t aslında daha genel bir shape
    if (wrapper == NULL)                        //Daireyi (circle_t) bu sarmalayıcıya koyuyoruz, böylece SVG kütüphanemizde tüm şekiller (circle, rectangle, square, vb.) aynı şekilde işlenebilir.

                                                //Eğer sarmalayıcı için bellek yetmezse: boş döner 
    {
        free(shape); 
        return NULL;
    }

    wrapper->shape = shape;                     // circle_t pointer’ını sarmalayıcıya koyduk , buna gerek var çünkü  her şeklin iç yapısı farklı 
    wrapper->fillColor = fillColor;             //iç renk
    wrapper->strokeColor = strokeColor;         // kenar rengi
    wrapper->strokeWidth = strokeWidth;         // kenar kalınlığı
    wrapper->saveFunc = &circle_save;           // SVG olarak kaydetmek için fonksiyon pointer’ı
                                                // -> kağıtta yazıyor
    return wrapper;
}

void circle_save(shape_t* instance, FILE* file) // Bu fonksiyon, bir circle nesnesini SVG dosyasına yazmak için kullanılır.

{
    circle_t* c = (circle_t*)instance->shape;  //s Kaydedilecek şeklin (circle) bilgilerini tutan bir pointer. instance burada circle nesnesini sarıyor.
    fprintf(file, "<circle cx=\"%i\" cy=\"%i\" r=\"%i\" stroke-width=\"%i\" fill=\"", c->cx, c->cy, c->r, instance->strokeWidth);
    color_fprint(&instance->fillColor, file);   //
    fprintf(file, "\" stroke=\""); 
    color_fprint(&instance->strokeColor, file);
    fprintf(file, "\" />");                      //"/> ile SVG daire etiketi tamamlanıyor.
    // buarada sadece circle* var çünkü sadece void ile tek bir fonksyon çalıştırıyoruz 1
}


