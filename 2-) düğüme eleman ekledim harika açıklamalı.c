#include <stdio.h>
#include <stdlib.h>
struct dugum {   // ilk düğüm olutşruma struct yazdık
    
    int veri;
    struct dugum *gosterici;

};
struct dugum *bas = NULL; // başlangıç değeri yarattım
struct dugum *gecici=NULL;// daha sonra başlangıçtaki değeri olup olmadığını tespit etmek için gecici bir düğüm oluşturdum

void sonaEkle(int sayi){  
    struct dugum * eklenecek ; // eklenecek olan düğümün yapsını oluşturdum 
    eklenecek = (struct dugum*)malloc(sizeof(struct dugum)); // düğüme değer atamak için malloc komutuyla yer açtırdım
    eklenecek ->veri=sayi; // daha sonrasında girilen sayıyı eşitledim verisine 
    eklenecek ->gosterici=NULL; // göstericisine nullı çaktım çünkü sondaki değer 

if(bas==NULL){ // eğerki başlangıçta bi değer yoksa yani bi düğüm yoksa eklenecek olan değeri başa eşitledim
    bas=eklenecek;
}
else{  // eğer başlangıçta eklenecek bi değer varsa gecici bi düğüm oluşturdum ve while döngüsüyle düğümleri tarattım verisine git adresine git diye
    gecici=bas;
    while(gecici->gosterici!=NULL){
        gecici=gecici->gosterici; // düğümleri gezmeye yarıyor 
    }
    gecici->gosterici=eklenecek; // son düğümü bulup eklenecek olan düğüme eşitledim
}

}
void yazdir(){  // sonra yazdırma fonksiyonuyla girdim işe 
    gecici=bas;
    while(gecici->gosterici!=NULL){ // bütün değerleri tarattım 
        printf("%d\n",gecici->veri); // tarattığım değerleri yazdırdım 
        gecici=gecici->gosterici; 
    }
    printf("%d\n",gecici->veri); // sondaki null gösterdiği için döngüye girmedi bu nedenle sondakini birdaha yazdırdım
}

int main(){
    int sayi;
    for(int i =0 ; i<5 ; i++){
    printf("sayı girin\n");
    scanf("%d",&sayi);
    sonaEkle(sayi);
    }
    yazdir();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct dugum{
    int veri;
    struct dugum * gosterici;
};
struct dugum *bas=NULL;
struct dugum *gecici=NULL;

void sonaEkle(int sayi){
    struct dugum * eklenecek;
    eklenecek=(struct dugum * )malloc(sizeof(struct dugum));
    eklenecek->veri=sayi;
    eklenecek->gosterici=NULL;
}
/*
if(bas==NULL){
    bas=eklenecek;
}
else{
    gecici=bas;
    while(gecici->gosterici!=NULL){
        gecici=gecici->gosterici;
    }
    gecici->gosterici=eklenecek;
}

/*void yazdir(){
gecici=bas;
while(gecici->gosterici!=NULL ){
    printf("%d",gecici->veri );
    gecici=gecici->gosterici;

}
printf("%d",gecici->veri);
}


int main()
{   int sayi;
    for(int i =0 ; i<5 ; i++){
     printf("sayı girin\n");
        scanf("%d",&sayi);
        sonaEkle(sayi);
        yazdir();

    }


    return 0;
}
