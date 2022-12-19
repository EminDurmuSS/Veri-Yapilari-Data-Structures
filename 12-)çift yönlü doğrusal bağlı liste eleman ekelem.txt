#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct node{
    int data ;
    struct node * next;
    struct node *prev;
};
struct node *temp=NULL;
struct node *start=NULL;
struct node *prev=NULL;
struct node *temp2=NULL;

void BasaEkle(int sayi){
    struct node *eleman;
    eleman=(struct node *) malloc(sizeof(struct node));
    eleman->data=sayi;
    eleman->prev=NULL;
    if(start==NULL){
        start=eleman;
        start->next=NULL;
    }
    else{
            eleman->next=start;
            start=eleman;
    }


}
void SonaEkle(int sayi){
    struct node *eleman;
    eleman=(struct node *) malloc(sizeof(struct node));
    eleman->data=sayi;
    eleman->next=NULL;
    if(start==NULL){
        start=eleman;
        start->next=NULL;
    }

    if(start->next==NULL){
        start->next=eleman;
        eleman->prev=start;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
        temp=temp->next;
    }
     temp->next=eleman;
     eleman->prev=temp;
    }


}
void bastanSil(){
    if(start==NULL){
        printf("Silinecek eleman yok \n");
    }
    else{
        if(start->next==NULL){
            free(start);
            start=NULL;
        }
        else{
            temp=start->next;
            free(start);
            temp->prev=NULL;
            start=temp;
        }
    }
}
void sondanSil(){
    if(start==NULL){
        printf("Silinecek eleman yok \n");
    }
    else{
        if(start->next==NULL){
            free(start);
            start=NULL;
        }
        else{
            temp=start;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp2=temp;
            free(temp->next);
            temp2->next=NULL;
        }

    }
}
void yazdir(){
    system("cls");
    if(start==NULL){
        printf("Listede hiç eleman yok \n ");
    }
    else{
    temp=start;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
}
    printf("%d",temp->data);
}
}
int main(){
    int sayi, secim;
    setlocale(LC_ALL,"Turkish");
    printf("Çift yönlü doğrusal bağlı listeye HOŞGELDİNİZ \n");
    while(1){
    printf(" \n Başa eleman eklemek için 1 \n");
    printf("Sona eleman eklemek için 2 \n");
    printf("Baştan eleman silmek için 3 \n");
    printf("sondan eleman silmek için 4 \n");
    scanf("%d",&secim);
    switch(secim){
            case 1: printf(" başa Eklemek istediğiniz sayıyı giriniz \n") ;
            scanf("%d",&sayi);
            BasaEkle(sayi);
            yazdir();
            break;

            case 2: printf(" sona Eklemek istediğiniz sayıyı giriniz \n") ;
            scanf("%d",&sayi);
            SonaEkle(sayi);
            yazdir();
            break;

            case 3:
            bastanSil();
            yazdir();
            break;

            case 4:
            sondanSil();
            yazdir();
            break;

            }
}
    return 0;
}
