#include "svg.h"

svg_t* svg_new(const char* fileName, int width, int height) //Amaç: Yeni bir SVG nesnesi (dosya) oluşturmak.
{
    svg_t* result = malloc(sizeof(svg_t));  //malloc(sizeof(svg_t)) → Bellekten svg_t tipi için yer ayırıyor.
    if(!result) return NULL; // kontrol ediyoruz 

    result->fileName = fileName;  //fileName, width, height → SVG dosyasının ismi ve boyutu.
    result->width = width;
    result->height = height;
    result->head = NULL;
    result->tail = NULL;

    return result;
}

void svg_add(svg_t* instance, shape_t* shape)  //Amaç: Bir şekli (shape_t) SVG nesnesine eklemek.
{
    if(svg_is_empty(instance))   //SVG’nin bağlı listesi boşsa → shape hem head hem tail olur. (kontrol)
    {
        instance->head = shape;  //head → listenin ilk elemanı olur. (boşşa ekleme)
        instance->tail = shape;  //tail → listenin son elemanı olur (tek eleman olduğu için head=tail).
        return;
    }

    shape->next = NULL;        //SVG doluysa ekleme,yeni shape eklendiğinde sonraki elemanı yok, bu yüzden NULL atanır.   
    
    instance->tail->next = shape;   // Mevcut son shape’in (tail) next pointer’ı artık yeni shape’i gösterir.
    instance->tail = shape;         //tail pointer’ı artık listenin son elemanı olan yeni shape’i gösterir.
    instance->tail = shape;         
}

bool svg_is_empty(svg_t* instance)
{
    return instance->head == NULL; //SVG nesnesinde hiç shape yoksa head pointer’ı NULL olur.
}                                  // true → SVG boş
                                   // //false → SVG’de en az bir shape var

                                   
                            
                                 

void svg_save(svg_t* instance)    
{
    FILE* svgFile;
    svgFile = fopen(instance->fileName, "w");   //fopen → Belirtilen dosya adını açar (write modunda).
    
    //SVG dosyaları XML formatında olduğu için başına XML ve DTD satırlarını ekliyoruz.

    fprintf(svgFile, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
    fprintf(svgFile, "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">");

    fprintf(svgFile, "<svg width=\"%i\" height=\"%i\" xmlns=\"http://www.w3.org/2000/svg\">", instance->width, instance->height); //SVG’nin ana <svg> etiketi oluşturulur.
    if(!svg_is_empty(instance))
    {
        shape_t* current = instance->head;
        while (current != NULL)
        {
            current->saveFunc(current, svgFile); // Pointeur de fonction pour générer la balise SVG du shape
            current = current->next;
        }
    }    
    fprintf(svgFile, "</svg>");

    fclose(svgFile); 

    /*
    Eğer SVG boş değilse:

current → listenin ilk shape’i (head).

while döngüsü ile tüm shape’ler gezilir.

current->saveFunc(current, svgFile) → Her shape’in kendi SVG etiketi dosyaya yazılır.

Örn: circle → <circle>, rectangle → <rect>

current = current->next → Sonraki shape’e geçer.

Bu mantıkla SVG dosyası içindeki tüm şekiller yazılır.
    */
}

void svg_free(svg_t* instance)
{
    if(!svg_is_empty(instance))
    {
        shape_t* current = instance->head;
        while (current != NULL)
        {
            shape_t* next = current->next; 
            shape_free(current);
            current = next;
        }
    }

    free(instance);
/*
SVG bellekte dinamik olarak oluşturulmuş bir yapıdır, kullanımdan sonra temizlenmelidir.

Eğer SVG boş değilse:

current → head’ten başlar.

next → sonraki shape’i tutar (current silindikten sonra kaybolmaması için).

shape_free(current) → shape’in kendisini ve içindeki verileri temizler.

current = next → bir sonraki shape’e geçer.

Son olarak free(instance) → SVG nesnesinin kendisi bellekten silinir.*/

}