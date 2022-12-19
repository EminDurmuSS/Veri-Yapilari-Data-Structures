#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct node{
    int data ;
    struct node *next;
};
struct node *temp=NULL;
struct node *bas=NULL;
void BasaEkle(int sayi){
    struct node *eklenecek;
    eklenecek=(struct node *)malloc(sizeof(struct node));
    eklenecek->data=sayi;
    eklenecek->next=bas;
    bas=eklenecek;
}
void SonaEkle(int sayi){
    struct node *eklenecek;
    eklenecek=(struct node*)malloc(sizeof(struct node));
    eklenecek->data=sayi;
    eklenecek->next=NULL;


if(bas==NULL){
    bas=eklenecek;
}
else{
    temp=bas;
    while(temp->next!=NULL){
        temp=temp->next;

    }
temp->next=eklenecek;

}


}

void yazdir(){
    temp=bas;
    while(temp->next!=NULL){
        printf("%d \n",temp->data);
        temp=temp->next;
    }
        printf("%d \n",temp->data);



}
int main(){
    setlocale(LC_ALL,"Turkish");
    int sayi;
    for(int i =0; i<5;i++){
    printf("Lütfen eklemek istediğiniz sayıyı giriniz  \n");
    scanf("%d",&sayi);
    SonaEkle(sayi);

    }
yazdir();


    return 0;
}
