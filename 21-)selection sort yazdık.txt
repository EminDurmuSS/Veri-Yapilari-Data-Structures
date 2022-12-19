#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100


void bublesort( int dizi[],int boyut){
    for(int i=0;i<boyut;i++){ // boyut kadar eleman taratılacak
        for(int j=1;j<boyut-i;j++){// boyutun i kadar eksiği kadar eleman tartılıcak çünkü ilk gidişte 5 kere 2. gidişte 4 kere tarıyacak bulucak ya ona öyle sonra 3 kere gideceği için boyutun i kadar eksiği
            if(dizi[j-1]>dizi[j]){// ardışık terimlerini kontrol ediyoruz
                int temp = dizi[j];
                dizi[j]=dizi[j-1];
                dizi[j-1]=temp;


            }

        }

    }

}

void selectionSort(int dizi[],int boyut){
    int i,j,enkucukindex;
    for(i=0;i<boyut;i++){
            enkucukindex=i;
        for(j=i;j<boyut;j++){
            if(dizi[enkucukindex]>dizi[j]){
                enkucukindex=j;
            }

        }
       int temp=dizi[i];
       dizi[i]=dizi[enkucukindex];
       dizi[enkucukindex]=temp;


    }



}



int main(){
    setlocale(LC_ALL,"Turkish");
    int sayiDizisi[MAX],boyut;
    printf("Kaç elemanlı bir dizi oluşturmak istiyorsunuz \n");
    scanf("%d",&boyut);
    printf("Dizinin elemanlarını giriniz \n");
    for(int i=0;i<boyut;i++){
        printf("%d eleman = ",i+1);
        scanf("%d",&sayiDizisi[i]);
    }
    for(int i=0;i<boyut;i++){
    printf("%d ",sayiDizisi[i]);}
    printf("\n");
    selectionSort(sayiDizisi,boyut);
    for(int i=0;i<boyut;i++){
    printf("%d ",sayiDizisi[i]);
    }



    return 0;
}
