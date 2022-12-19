#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define boyut 7
struct node {
    int data;
    struct node *next;
};
struct node *dizi[boyut];
struct node *temp=NULL;
void nulacevir (){
    int i;
for(i=0;i<boyut;i++){
    dizi[i]=NULL;
}
}
void hashekle(int veri,int modualinacak){
    struct node *yeninode;
    yeninode=(struct node *)malloc(sizeof(struct node));
    yeninode->data=veri;
    yeninode->next=NULL;

    int key=modualinacak%boyut;

    if(dizi[key]==NULL){
        dizi[key]=yeninode;
    }
    else{
            temp=dizi[key];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=yeninode;
    }

}
void yazdir(){
    int i;
    for(i = 0; i < boyut; i++)
    {
        temp = dizi[i];
        printf("dizi[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


int main(){
    setlocale(LC_ALL,"Turkish");
    nulacevir();
    int veri;
    int adet=0;
    int modualinacak;
    printf("****Hash Tablosu******\n");
    while(adet!=6){
    printf("Düğümün modu alınacak olan sayısını giriniz \n");
    scanf("%d",&modualinacak);
    printf("düğüme eklemek istediğinz sayıyı giriniz \n");
    scanf("%d",&veri);
    hashekle(veri,modualinacak);
    yazdir();
    adet++;
    }
    return 0;
}
