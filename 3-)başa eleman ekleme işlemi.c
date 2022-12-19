#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct dugum{
    int veri;
    struct dugum *gosterici;
};
struct dugum *bas=NULL; //EMİN DURMUŞ
struct dugum *gecici=NULL;

void basaEkle(int sayi){
    struct dugum *eklenecek;
    eklenecek =(struct dugum *)malloc(sizeof (struct dugum));
    eklenecek->veri=sayi;
    eklenecek->gosterici=bas;
    bas=eklenecek;
}
void yazdir(){
    gecici=bas;
    while(gecici->gosterici!=NULL){
        printf("\n%d\n",gecici->veri);
        gecici=gecici->gosterici; // düğümlerde gezmek için
    }
    printf("\n%d\n",gecici->veri);
}

int main(){
    int sayi;
    setlocale(LC_ALL,"turkish");
    printf("Merhaba arkadaşlar bugün sizlerle bir düğümde başa eleman eklemeyi anlatacam \n");
   for(int i =0;i<6;i++){
    printf("Lütfen bir sayı gir kanki \n");
    scanf("%d",&sayi);
    basaEkle(sayi);
    }
    yazdir();

    return 0;
}
