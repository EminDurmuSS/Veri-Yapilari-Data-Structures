#include <stdio.h>
#include <stdlib.h>
#define BOY 10
#include <locale.h>
struct stack{
    int dizi[BOY];
    int top;
};
struct stack y1;
void PUSH(int sayi){
    if(y1.top==BOY-1){
        printf("Stack yapısı DOLUDUR ! \n");
    }
    else{
        y1.top++;
        y1.dizi[y1.top]=sayi;
    }

}
void POP(){
    if(y1.top==-1){
        printf("Silinecek eleman yoktur \n");
    }
    else{
        printf("çıkarılan eleman = %d \n",y1.dizi[y1.top]);
        y1.top--;
    }
}
void yazdir(){
    system("COLOR A");

    system("cls");
    if(y1.top==-1){
        printf("Görüntülenecek eleman yoktur \n");
    }
    else{
        for(int i=y1.top;i>=0;i--){
              printf(" %d\n ",y1.dizi[i]);
        }
    }

}

int main(){
system("COLOR A");

    y1.top=-1;
    setlocale(LC_ALL,"Turkish");
    while(1){
    printf("ELEMAN EKLEMEK İÇİN 1 \n");
    printf("ELEMAN SİLMEK İÇİN 2 \n");
    printf("LÜtfen seçiminizi yapınız \n");
    int secim;
    int sayi;
    scanf("%d",&secim);
    switch(secim){
    case 1:printf("Başa ekliyeceğiniz sayıyı giriniz \n");
           scanf("%d",&sayi);
           PUSH(sayi);
           yazdir();
           break;

    case 2 :printf("pop işlemi gerçekleştirildi \n");
            POP();
            yazdir();
            break;
    }
    }
    return 0;
}
