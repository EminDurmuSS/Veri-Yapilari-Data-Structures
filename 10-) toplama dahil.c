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
    while(temp->next!=NULL){ // deðerleri taramak
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
void bastanSil(){
    temp=start->next;
    free(start);
    start=temp;
}
void sondanSil(){
    if(start->next!=NULL ){
    temp=start;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;

}
else
    bastanSil();
}
void yazdir(){
    system("cls");
    if(start!=NULL){
    temp=start;
    while(temp->next!=NULL){
        printf("% d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
    }
    else{
        printf("ELEMAN YOK \n");
    }

}
void arayaEkle(int veri,int n){
    struct node *eklenecek;  // araya eklenecek olan düðümü yazdýrdým.
    eklenecek=(struct node*)malloc(sizeof(struct node));
    eklenecek->data=veri;

    temp=start;
    while(temp->next->data!=n){  // hangisinden önce istediðim düðümü yazdýrdým
        temp=temp->next;
    }
    struct node *temp2;
    temp2=(struct node*)malloc(sizeof(struct node));

    temp2=temp->next;
    temp->next=eklenecek;
    eklenecek->next=temp2;



}
void aradanSil(int veri){
    temp=start;
    if(temp->data==veri){
        bastanSil();
    }
    else{
        struct node *temp2;
        temp2=(struct node*)malloc(sizeof(struct node ));
        while(temp->next->data!=veri){
            temp=temp->next;
        }
        if(temp->next->next==NULL){
            sondanSil();
        }
        else{
            temp2=temp->next->next;
            free(temp->next);
            temp->next=temp2;

        }



    }

}
void tersCevir(){
    struct node *temp2;
    struct node *prev;

    temp=start;
    while(temp!=NULL){
        temp2=temp->next;// tempin nextini temp 2 yaptýk yani sonraki elemaný
        temp->next=prev; // tempin nextine bi düðüm inþa ettim
        prev=temp; // inþa ettiðim düðümün deðerlerini filan tempe baþlangýç deðere eþitledim
        temp=temp2; // oluþturmuþ olduðum ilk düðümün deðerlerinide sonraki deðerleriin içine attým

    }
    start = prev;
}
int elemanSayisi(){
    int adet = 0;
    if(start==NULL){
        return adet;

    }
    else{
        temp=start;
        while(temp->next!=NULL){
            adet++;
            temp=temp->next;
        }
        adet++;
        return adet;
    }
}
int elemanToplami(){
    int toplam = 0;
    if(start==NULL){
        return toplam;

    }
    else{
        temp=start;
        while(temp->next!=NULL){
            toplam+=temp->data;
            temp=temp->next;
        }
    toplam+=temp->data;
        return toplam;
    }
}
int main(){
    int secim;
    int sayi;
    int adet=0;
    int n =0;
    int veri;
  setlocale(LC_ALL,"Turkish");
  while(adet!=10){
  printf("\n Lütfen seçim yapýnýz -->  ");
  printf("baþa ekle 1\n");
  printf("sona ekle 2\n");
  printf("araya ekle 3\n");
  printf("baþtan sil 4\n");
  printf("sondan sil 5\n");
  printf("aradan sil 6 \n");
  printf("Ters çevir 7\n");
  printf("eleman adeti 8\n");


  scanf("%d",&secim);
  printf("\nseçiminiz %d \n",secim);
  switch(secim){
  case 1:
        printf("\n Baþa Ekleme seçimi yapýldý \n");
        printf("\n Lütfen bir sayý giriniz.\n");
        printf("\n Eklediðiniz sayi : ");
        scanf("%d",&sayi);
        basaEkle(sayi);
        yazdir();
        break;

  case 2:printf("sona Ekleme seçimi yapýldý \n");
            printf("Lütfen bir sayý giriniz\n");
            scanf("%d",&sayi);
            sonaEkleme(sayi);
            yazdir();
            break;



  case 3:   printf("araya Ekleme seçimi yapýldý \n");
            printf("Lütfen hangi sayýdan önce  eklemek istiyorsunuz\n");
            scanf("%d",&n);
            printf("girilicek sayýyý giriniz \n");
            scanf("%d",&sayi);
            arayaEkle(sayi,n);
            yazdir();
            break;



  case 4: printf("\nBaþtan eleman siliniyor \n");
          bastanSil();
          yazdir();
          break;



   case 5: printf("\n Sondan eleman siliniyor \n");
        sondanSil();
        yazdir();
        break;

    case 6:

        printf("\n aradan eleman siliniyor \n");
        printf(" aradan silmek istediðiniz sayýyý giriniz \n");
        scanf("%d",&veri);
        aradanSil(veri);
        yazdir();
        break;

        case 7: printf("\n Ters çevriliyor \n");
        tersCevir();
        yazdir();
        break;


        case 8: printf(" eleman adeti %d \n",elemanSayisi());
        break;

        case 9:
        printf("eleman toplamı = %d \n",elemanToplami());
        break;
}

   adet++;
  }
    return 0;


}

