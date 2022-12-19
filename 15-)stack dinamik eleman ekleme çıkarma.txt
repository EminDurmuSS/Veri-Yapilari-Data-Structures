#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct node{
    int data;
    struct node *next;

};
struct node *top=NULL;
struct node *temp=NULL;

void push(int sayi){
    struct node * eleman;
    eleman=(struct node *)malloc(sizeof(struct node ));
    eleman->data=sayi;

    if(top==NULL){ 
    top=eleman;
    top->next=NULL;
    }
    else{
        eleman->next=top;
        top=eleman;
    }
}
void pop(){
    if(top==NULL){
        printf("Düğümde silinecek eleman yok \n");
    }
    else{
        printf("%d elemanı çıkarıldı",top->data);
        temp=top->next;
        free(top);
        top=temp;
    }



}
void yazdir(){
    system("cls");
    if(top==NULL){
        printf("silinecek eleman yok \n");
    }
    else{
    temp=top;

    while(temp->next!=NULL){
        printf("%d \n",temp->data);
        temp=temp->next;
    }

    printf("%d\n",temp->data);
    }
}


int main(){
    setlocale(LC_ALL,"Turkish");
    int secim;
    int sayi;
    while(1){
    printf("*****Stack - Dinamik *****\n");
    printf("Push choise =1 \n");
    printf("pop choise = 2 \n");
    scanf("%d",&secim);
    switch(secim){
    case 1: printf("Eklemek istediğiniz elemanı giriniz = ");
            scanf("%d",&sayi);
            push(sayi);
            yazdir();
            break;

    case 2: pop();
            yazdir();
            break;
    }
    }
    return 0;
}
