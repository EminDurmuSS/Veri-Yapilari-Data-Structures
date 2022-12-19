#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100
void insertionSort(int dizi[],int boyut){
    for(int i=1;i<boyut;i++){ // dizinin elemanlarını taramak için
        for(int j=i;j>0;j--){ // 2. elemandan başlamak için i ye eşitledim
            if(dizi[j]<dizi[j-1]){
                int temp=dizi[j];     
                dizi[j]=dizi[j-1];    
                dizi[j-1]=temp;

            }
        }

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
    insertionSort(sayiDizisi,boyut);
    for(int i=0;i<boyut;i++){
    printf("%d ",sayiDizisi[i]);
    }



    return 0;
}
