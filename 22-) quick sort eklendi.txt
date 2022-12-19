#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100
#include <string.h>
void BubleSort(int dizi[],int boyut){
    for(int i =0;i<boyut;i++){
        for(int j=1;j<boyut-i;j++){
            if(dizi[j-1]>dizi[j]){
                int temp = dizi[j];
                dizi[j]=dizi[j-1];
                dizi[j-1]=temp;
            }
        }
    }

}

void SelectionSort(int dizi[],int boyut){
    int i;
    for(i=0;i<boyut;i++){
        int enkucukindex = i;
        for(int j=i;j<boyut;j++){
            if(dizi[j]<dizi[enkucukindex]){
                enkucukindex=j;
            }

            }
        int temp=dizi[i];
        dizi[i]=dizi[enkucukindex];
        dizi[enkucukindex]=temp;

    }


}
void insertionSort(int dizi[],int boyut){
    for(int i=1;i<boyut;i++){
        for(int j=i;j>0;j--){
            if(dizi[j]<dizi[j-1]){
                int temp=dizi[j];
                dizi[j]=dizi[j-1];
                dizi[j-1]=temp;
            }
        }


    }


}
void quickSort(int dizi[],int bas,int son){
    int i,j,pivot,temp;
    i=bas;
    j=son;
    pivot=(dizi[i]+dizi[j])/2;
    do{
            while(dizi[i]<pivot){
                i++;
            }
            while(dizi[j]>pivot){
                j--;
            }
            if(i<=j){
                temp =dizi[i];
                dizi[i]=dizi[j];
                dizi[j]=temp;
                i++;
                j--;
            }


    }while(i<j);
    if(i<son){
        quickSort(dizi,i,son);
    }
    if(j>bas){
        quickSort(dizi,bas,j);
    }


}


int main(){
    setlocale(LC_ALL,"Turkish");
    int sayiDizisi[MAX],boyut;
    printf("İNSERTİON SORT BUBLE SORT SELECTİON SORT LETSSSGOO\n");
    printf("Kaç elemanlı bir dizi oluşturmak istiyorsunuz.\n");
    scanf("%d",&boyut);
    printf("dizinin elemanlarını giriniz \n");
    for(int i=0;i<boyut;i++){
        scanf("%d",&sayiDizisi[i]);
    }
    printf("\n");
    for(int i=0;i<boyut;i++){
        printf("%d ",sayiDizisi[i]);
    }
  printf("\n Lütfen bir seçim yapınız--> Buble Sort 1 \n  Selection sort  (2) \n insertion sort ekle (3) \n quickSort (4) \n  ");
  int secim;
  scanf("%d",&secim);
  printf("\nseçiminiz %d \n",secim);
    switch(secim){
    case 1 :
    BubleSort(sayiDizisi,boyut);
        printf("\n");
    for(int i=0;i<boyut;i++){
        printf("%d ",sayiDizisi[i]);

    }
    break ;

    case 2 :
    SelectionSort(sayiDizisi,boyut);
        printf("\n");
    for(int i=0;i<boyut;i++){
        printf("%d ",sayiDizisi[i]);

    }
    break ;

    case 3 :
    insertionSort(sayiDizisi,boyut);
        printf("\n");
    for(int i=0;i<boyut;i++){
        printf("%d ",sayiDizisi[i]);

    }
    break ;



    case 4 :
    quickSort(sayiDizisi,0,boyut-1);
        printf("\n");
    for(int i=0;i<boyut;i++){
        printf("%d ",sayiDizisi[i]);

    }
    break ;


}


    return 0;
}
