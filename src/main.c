#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "svg.h"
#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "shapes/ellipse.h"
#include"shapes/square.h" // C’de bir fonksiyonu kullanmadan önce prototipini bilmek gerekir.

                          //Çözüm: main.c başına ekle


bool tryReadInt(int* result)
{
    if (scanf("%d", result) != 1 || ferror(stdin) != 0)  //!= 1 demek, eğer bir tane doğru sayı okunmadıysa hata var demektir.
    {
                                                    //ferror(stdin) → girdi akışında bir hata olup olmadığını kontrol eder.
        int c;
        while ((c = getchar()) != EOF && c != '\n'); //  getchar() ile kullanıcı ne kadar saçma şey yazdıysa hepsini temizler (boşaltır).
        while ((c = getchar()) != EOF && c != '\n'); // neden iki satır var? -
        printf(RED "Entrée invalide\n" RESET);       // Ekrana “Entrée invalide” (Geçersiz giriş) yazar.
        return false;                                // function bış döner.
    }

    return true;
}

int main(void) 
{ 
    printf(GREEN "red\n" RESET);                      
    color_t red = {255, 100, 100};
    printf("#%02x%02x%02x\n", red.r, red.g, red.b);

    printf(CYAN "blue\n" RESET);
    color_t blue = {100, 100, 255};
    printf("#%02x%02x%02x\n", blue.r, blue.g, blue.b);

    printf(MAGENTA "black\n" RESET);
    color_t black = {0, 0, 0};
    printf("#%02x%02x%02x\n", black.r, black.g, black.b);

    svg_t* svg = svg_new("export.svg", 200, 200);
    if (!svg) 
    {
        fprintf(stderr, RED "Erreur: impossible de créer export.svg\n" RESET);
        return EXIT_FAILURE;
    }

    int choix = 0;
    while (1) 
    {
        printf("\n" YELLOW "=== MENU PRINCIPAL ===\n" RESET);   //ana menu sonsuz bir döngü
        printf(BLUE   "1. Ajouter un rectangle\n" RESET);       //
        printf(GREEN  "2. Ajouter un cercle\n" RESET);
        printf(PURPLE "3. Ajouter une ellipce\n" RESET);
        printf(GRAY   "4. Ajouter un carrée\n" RESET );
        printf(RED    "5. Sauvegarder et quitter\n" RESET);
        printf(CYAN   "Votre choix: " RESET);
        
        if (!tryReadInt(&choix)) continue;

        if (choix == 1) 
        {
            int x, y, w, h;
            printf("Position X: ");
            if (!tryReadInt(&x)) continue; //tryReadInt senin yazdığın bir yardımcı (helper) fonksiyon. Amacı, kullanıcıdan güvenli bir şekilde tamsayı almak.

            //Normal scanf("%d", &x) tehlikeli olabilir:
            
            printf("Position Y: ");
            if (!tryReadInt(&y)) continue;
            printf("Largeur: ");
            if (!tryReadInt(&w)) continue;
            printf("Hauteur: ");
            if (!tryReadInt(&h)) continue;

            svg_add(svg, rect_create(blue, black, 1, x, y, w, h));  // mavi renkli bir dikdörtgen oluşturur
            printf(GREEN "Rectangle ajouté avec succès !\n" RESET); 
            // neden "scanf" yok - on a remplace par scanf "tryReadInt "
        }
        else if (choix == 2) 
        {
            int x, y, r;
            printf("Centre X: "); if (!tryReadInt(&x)) continue;    //kımızı renkli bir daire oluşturur.
            printf("Centre Y: "); if (!tryReadInt(&y)) continue;   // "!" mantık:“Kullanıcıdan geçerli bir sayı alınamazsa, bu turu atla ve tekrar sor.”
            printf("Rayon R: ");  if (!tryReadInt(&r)) continue;

            svg_add(svg, circle_create(red, black, 1,x,y,r));   
            printf(GREEN "Cercle ajouté avec succès !\n" RESET);
        } 
        else if (choix==3)
        {
            int cx, cy, rx, ry;
            printf("Centre X:"); if (!tryReadInt(&cx)) continue; // kırmızı renkli bir elips oluşturur.
            printf("Centre Y:"); if (!tryReadInt(&cy)) continue;
            printf("Rayon X:");  if (!tryReadInt(&rx)) continue;
            printf("Rayon Y:");  if (!tryReadInt(&ry)) continue;

            svg_add(svg, ellipse_create(red, black, 1,cx, cy,rx,ry));
            printf(PURPLE "Ellipse ajouté avec succès\n" RESET);
        }
        else if (choix==4)
        {
            int x,y,w;
            printf("Position X:"); if(!tryReadInt(&x)) continue;
            printf("Position Y:"); if(!tryReadInt(&y)) continue;
            printf("Width W:");    if(!tryReadInt(&w))  continue;

            svg_add(svg, square_create(red,black,1,x,y,w));
            printf(GRAY "Carrée ajouté avec succès\n" RESET);
        }
        else if (choix == 5)   // uygulamayı kaydedip kapatır.
        {   
            svg_save(svg);
            svg_free(svg);
            printf(MAGENTA "Fichier 'export.svg' sauvegardé. Bye !\n" RESET);
            break;
        } 
        else 
        {   // eğer yukarıdakilerden hiçbiri değilse bu değer çalışır ve program hata verir. 
            printf(RED "Choix invalide, réessayez.\n" RESET);
        }
    }

    return EXIT_SUCCESS;
}

//"Main "
/*
Programın giriş noktası (entry point).
Kullanıcıyla etkileşimi sağlar (menü, inputlar), şekilleri oluşturur ve SVG’ye ekler.

İçerdiği önemli parçalar:

tryReadInt() → Kullanıcıdan güvenli şekilde tam sayı almak için.

scanf hatalı input’larda bozulabilir, hatayı önler.

Her seçimde kullanıcıdan gerekli veriler alınır (x, y, r, w, h gibi),
ilgili şekil oluşturma fonksiyonu çağrılır (rect_create, circle_create...),
sonra bu şekil svg_add fonksiyonuyla SVG yapısına eklenir.
*/