#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct node{
    struct node *next;
    int data;

};
struct node *temp=NULL;
struct node *start=NULL;
struct node *prev=NULL;
struct node *last=NULL;



void BasaEkle(int sayi){

    struct node *eleman;
    eleman=(struct node *)malloc(sizeof(struct node ));
    eleman->data=sayi;

    if(start==NULL){
            start=eleman;
        eleman->next=eleman;

}

    else{
            temp=start;
            while(temp->next!=start){
                temp=temp->next;
            }
            temp->next=eleman;
            eleman->next=start;
            start=eleman;
    }


}
void bastanSil(){
    if(start==NULL){
        printf("hiç eleman yok \n");

    }
    else{
        if(start->next==start){
            free(start);
        }
        else{
              last=start;
              while(last->next!=start){
                last=last->next;

              }
              temp=start->next;
              free(start);
              last->next=temp;
              start=temp;
        }



    }



}
void sondanSil(){
    if(start==NULL){
        printf("hiç eleman yok \n");

    }
    else{
        if(start->next==start){
            free(start);
            start=NULL;
        }
        else{
              last=start;
              while(last->next->next!=start){
                last=last->next;

              }

             temp=last;
             free(last->next);
             last->next=start;

        }



    }



}
void SonaEkle(int sayi){






    struct node *eleman;
    eleman=(struct node *)malloc(sizeof(struct node ));
    eleman->data=sayi;

    if(start==NULL){
            start=eleman;
        eleman->next=eleman;

}

    else{
            temp=start;
            while(temp->next!=start){
                temp=temp->next;
            }
            temp->next=eleman;
            eleman->next=start;

    }


}



void yazdir(){

    system("cls");
    if(start==NULL){
        printf("eleman yok \n");

    }
    else{


    temp=start;
    while(temp->next!=start){
        printf("%d ",temp->data);
        temp=temp->next;

    }
    printf("%d",temp->data);

}
}




int main(){
    setlocale(LC_ALL,"Turkish");
    int secim;
    int sayi;
    while(1){
    printf("\n Tek yönlü dairsel bağlı liste eleman ekleme yapmak istediğiniz seçimi işaretleyin \n");
    printf("Başa elaman eklemek için 1 \n");
    printf("Sona eleman eklemek için 2 \n");
    printf("baştan silmek için 3 \n ");
    printf("sondan silmek için 4 \n");
    printf("Seçiminiz = ");
    scanf("%d",&secim);
    switch(secim){
    case 1 :
        printf("Eklemek istediğiniz sayıyı giriniz \n");
        scanf("%d",&sayi);
        BasaEkle(sayi);
        yazdir();
        break;

    case 2 :
        printf("Ekelemek istediğiniz sayıyı giriniz \n");
        scanf("%d",&sayi);
        SonaEkle(sayi);
        yazdir();
        break;


    case 3:
         bastanSil();
         yazdir();
         break;

    case 4:sondanSil();
            yazdir();
            break;

        }
}
    return 0;
}
