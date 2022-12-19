#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct node{
    int data;
    struct node * next;
};
struct node *temp=NULL;
struct node *front=NULL; // Kuyruktaki baştaki eleman
struct node *rear=NULL; // kuyruktaki sondaki eleman

void sonaEkle(int sayi){
    struct node *eleman=(struct node *)malloc(sizeof(struct node));
    eleman->data=sayi;

    if(front==NULL){ // listede tek eleman varsa 
        front=eleman;
        front->next=front;
        rear=eleman;
        rear->next=NULL;
    }
    else if(front->next==front){ // listede 1 eleman varsa 
        front->next=eleman;
        rear=eleman;
        rear->next=NULL;
    }
    else{   // listede birden fazla eleman varsa 
        rear->next=eleman;
        rear=eleman;
        rear->next=NULL;

    }

}

void elemanCikar(){
    if(front==NULL){
        printf("Çıkarılacak eleman yoktur \n");
    }
    else{
        temp=front->next;
        free(front);
        front=temp;
    }
}

void yazdir(){
    system("cls");
    if(front==NULL){
        printf("Yazdırılacak eleman yok \n");
    }
    else{
        temp=front;
        while(temp->next!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    printf("%d ",temp->data);
    }
}
int main(){
    setlocale(LC_ALL,"Turkish");
    int secim;
    int sayi;
    while(1){

        printf("\n****** QUEUE Veri yapısı *****\n ");
        printf("eklemek için 1 \n");
        printf("Silmek için 2 \n ");
        printf("Seçiminiz=  ");
        scanf("%d",&secim);
        switch(secim){

        case 1 :printf("Kuyruğa eklemek istediğiniz sayıyı giriniz \n");
                scanf("%d",&sayi);
                sonaEkle(sayi);
                yazdir();
                break;


         case 2 :
                elemanCikar(sayi);
                yazdir();
                break;



        }


    }



    return 0;
}
