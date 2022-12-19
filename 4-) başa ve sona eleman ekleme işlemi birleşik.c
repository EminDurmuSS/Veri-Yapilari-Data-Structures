#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *temp=NULL;

void sonaEkleme(int veri ){
    struct node *eklenecek;
    eklenecek=(struct node*)malloc(sizeof(struct node));
    eklenecek->data=veri;
    eklenecek->next=NULL;

if(start==NULL){
    start=eklenecek;
}
else{
    temp=start;
    while(temp->next!=NULL){ // değerleri taramak
        temp=temp->next;
    }
    temp->next=eklenecek;
}

}


void basaEkle(int veri){
    struct node *eklenecek;
    eklenecek = (struct node*)malloc(sizeof(struct node));
    eklenecek->data=veri;
    eklenecek->next=start;
    start=eklenecek;
}

void yazdir(){
    temp=start;
    while(temp->next!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);

}




int main(){
    int secim;
    int sayi;
    int adet=0;
  setlocale(LC_ALL,"Turkish");
  while(adet!=6){
  printf("\n Lütfen bir seçim yapınız--> başa ekle 1 sona ekle 2 \n  ");
  scanf("%d",&secim);
  printf("\nseçiminiz %d \n",secim);
  switch(secim){
  case 1:
        printf("\n Başa Ekleme seçimi yapıldı \n");
        printf("\n Lütfen bir sayı giriniz.\n");
        printf("\n Eklediğiniz sayi : ");
        scanf("%d",&sayi);
        basaEkle(sayi);
        yazdir();
        break;

  case 2:printf("sona Ekleme seçimi yapıldı \n");
            printf("Lütfen bir sayı giriniz\n");
            scanf("%d",&sayi);
            sonaEkleme(sayi);
            yazdir();
            break;
}
adet++;
}



    return 0;


}

