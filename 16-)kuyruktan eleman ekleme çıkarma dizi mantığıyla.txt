#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define BOY 10

int dizi[BOY];
int bas=-1;
int son=-1;

void ElemanEkleme(int sayi ){
    if(son==BOY-1){
        printf("Kuyruk full dolu \n");
    }
    else{
        if(bas==-1){
            bas=0;
        }

        son++;
        dizi[son]=sayi;

    }

}
void Elemancikar(){
    if(bas==-1||bas>son){
        printf("çıkarılacak eleman yok \n");
        bas=-1;
        son=-1;
    }
    else{
        bas++;
    }


}
void yazdir(){
    int i;
    for(i=bas;i<=son;i++){
    printf("%d",dizi[i]);
    }



}


int main(){
    setlocale(LC_ALL,"Turkish");
    int secim;
    int sayi;
    while(1){
    printf("*****Kuyruk veri yapısı dizi mantığıyla  *****\n");
    printf("Kuyruğa eleman eklemek için =1 \n");
    printf("kuyruktan eleman çıkarmak için = 2 \n");
    scanf("%d",&secim);
    switch(secim){
    case 1: printf("Eklemek istediğiniz elemanı giriniz = ");
            scanf("%d",&sayi);
            ElemanEkleme(sayi);
            yazdir();
            break;

    case 2: Elemancikar();
            yazdir();
            break;
    }
    }
    return 0;
}
