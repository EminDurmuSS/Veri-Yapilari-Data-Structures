#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct node {
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *temp = NULL;

void sonaEkle(int veri){
    struct node *eklenen ;
    eklenen=(struct node*)malloc(sizeof(struct node));
    eklenen->data=veri;
    eklenen->next=NULL;
  if(start==NULL){
    start=eklenen;

  }
else{
      temp=start;
      while(temp->next!=NULL){
        temp=temp->next;
      }
    temp->next=eklenen;

}
}
void basaEkle(int veri){
    struct node *eklenecek;
    eklenecek=(struct node*)malloc(sizeof(struct node));
    eklenecek->data=veri;
    eklenecek->next=start;
    start=eklenecek;
}
void yazdir(){
    temp=start;
    while(temp->next!=NULL){
        printf(" %d",temp->data);
        temp=temp->next;

    }
printf(" %d",temp->data);
}

int main(){
setlocale(LC_ALL,"Turkish");
    int adet=0;
    int secim;
    int sayi;
    while(adet!=6){
    printf("yapmak istediğiniz işlemi giriniz => 1 Başa ekleme 2 Sona ekleme ");
    scanf("%d",&secim);
    switch(secim){
    case 1:printf("\nEklemek istediğiniz sayıyı giriniz\n");
           scanf("%d",&sayi);
           basaEkle(sayi);
           yazdir();
           break;
    case 2:printf("\nEklemek istediğiniz sayıyı giriniz\n");
           scanf("%d",&sayi);
           sonaEkle(sayi);
           yazdir();
           break;

    }
   adet++;
   }

    return 0;
}
