#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100
void bublesort(int dizi[], int boyut){ // boyut diye açmamızın sebebi kullanıcıdan istiyebiliyor olmamız
    for(int i=0;i<boyut;i++){ //boyut kadar sayı göndermek
        for(int j=1;j<boyut-i;j++){ // yukarıdaki forun kısıtlamasıyla yazdığımız fonksiyonun ilk etapta 5 tur ikinci etapta 4 tur diye dönmesini sağlıyor
            if(dizi[j-1]>dizi[j]){ // burdaki i den çıkarmamızın sebebi şu makina verimliliği sağlamak yani döndün birdaha dönmene gerek yok gibisinden
                int temp =dizi[j-1];
                dizi[j-1]=dizi[j];
                dizi[j]=temp;
            }

        }
    }


}



int main(){
    setlocale(LC_ALL,"Turkish");
    int sayidizisi[MAX],boyut;
    printf("Dizinizin kaç boyutlu olmasını istediğini lütfen giriniz \n");
    scanf("%d",&boyut);
    printf("Dizinin elemanlarını giriniz \n");

    for(int i =0;i<boyut;i++){
    printf("%d ninci eleman",i+1);
    scanf("%d",&sayidizisi[i]);
    }
    for(int i =0;i<boyut;i++){
    printf("%d ",sayidizisi[i]);
    }
    printf("\n");
    bublesort(sayidizisi,boyut);

    for(int i =0;i<boyut;i++){
    printf("%d ",sayidizisi[i]);
    }



    return 0;
}

