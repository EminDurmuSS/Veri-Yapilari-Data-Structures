#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Ogrenci no 1210505049
//Ogrenci adı MUHAMMED EMİN DURMUŞ
//Kodlar hiçbir yerden alıntı değildir tamamen kendi hayal gücümü kullanarak yazdığım kodlardır
void linearSearch(int dizi[],int boyut,int aranan){
    int flag=0;
    for(int i =0;i<boyut;i++){
        if(dizi[i]==aranan){
            flag=1;
            break;
        }

    }
    if(flag==1){
        printf("\n Aramak istediğiniz sayıyı buldunuz = %d\n",aranan);
    }
    else{
        printf("\n Aramak istediğiniz sayı mevcut listede bulunmamaktadır = %d :-( \n",aranan);
    }


}

int main(){
    system("color a");
    int boyut,aranan;
    setlocale(LC_ALL,"Turkish");
    printf("VERİ YAPILARI VE ALGORİTMA ÖDEVİ \n");
    printf("1-)Lineer search yazdırılıcak \n");
    printf("Lütfen kaç elemanlı bir dizi oluşturmak istediğinizi giriniz \n");
    scanf("%d",&boyut);
    int dizi[boyut];
    printf("Dizinin elemanlarını giriniz \n");
    for(int i=0;i<boyut;i++){
        printf("Dizinin %d elemanı = ",i+1);
        scanf("%d",&dizi[i]);
    }
    printf("Algoritmada aranmasını istediğiniz sayıyı giriniz \n");
    scanf("%d",&aranan);
    printf("Aramak istediğiniz sayı %d",aranan);
    linearSearch(dizi,boyut,aranan);


    return 0;
}
