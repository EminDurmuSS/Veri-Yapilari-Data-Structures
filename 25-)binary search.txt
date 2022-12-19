#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void BinarySearch(int dizi[],int bas,int son,int aranan ){
    int flag=0;
    while(son>=bas){
    int orta=(dizi[(bas+son)/2]);
    if(orta==aranan){
    flag=1;
    break;
    }
    if(orta>aranan){
        son--;
    }
    if(orta<aranan){
        bas++;
    }

    }
    if(flag==1){
        printf("Aranan sayı bulundu dizinin %d indisinde  ",(bas+son)/2);
    }
    else{
        printf("bulunamadı \n");
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
    system("color b");
    int boyut;
    int aranan;
    int n;
    printf("Muhammed emin durmuş ödev 2 \n");
    printf("*******Binary search ********\n");
    printf("Lütfen kaç elemanlı bir dizi gireceğinizi belirtiniz \n");
    scanf("%d",&boyut);
    int dizi[boyut];
    printf("Lütfen dizinin elemanlarını giriniz \n ");
    for(int i =0;i<boyut;i++){
        printf("%d . elemanı = ",i+1);
        scanf("%d",&dizi[i]);
    }
    printf("Aramak istediğiniz sayıyı giriniz \n");
    scanf("%d",&aranan);
    printf("Giridiğiniz sayı dizisi sıralıysa 1 sıralı değilse 2 yi tuşlayınız \n");
    scanf("%d",&n);
    if(n==2){
        quickSort(dizi,0,boyut-1);
        printf("\nDizinin sıralı hali\n");
        for(int i =0;i<boyut;i++){
            printf("%d ",dizi[i]);
        }
    }
    BinarySearch(dizi,0,boyut-1,aranan);
    return 0;
}
