#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *temp=NULL;
struct node *start=NULL;
struct node *prev=NULL;
struct node *temp2=NULL;

void basaEkle(int sayi ){
    struct node *eleman;
    eleman=(struct node *)malloc(sizeof(struct node ));
    eleman->data=sayi;
    if(start==NULL){
        start=eleman;
        start->next=start;
        start->prev=start;
    }
    else{
        if(start->next==NULL){
            eleman=start->prev;
            start=eleman->next;
            start=eleman->prev;
            eleman=start->next;

            start=eleman;
        }
        else{
            temp=start;
            while(temp->next!=start){
                temp=temp->next;
            }
            temp->next=eleman;
            eleman->next=start;
            eleman->prev=temp;
            start->prev=eleman;

            start=eleman;
        }


    }


}
void sonaEkle(int sayi ){
    struct node *eleman;
    eleman=(struct node *)malloc(sizeof(struct node ));
    eleman->data=sayi;
    if(start==NULL){
        start=eleman;
        start->next=start;
        start->prev=start;
    }
    else{
        if(start->next==NULL){
            eleman=start->prev;
            start=eleman->next;
            start=eleman->prev;
            eleman=start->next;

        }
        else{
            temp=start;
            while(temp->next!=start){
                temp=temp->next;
            }
            temp->next=eleman;
            eleman->next=start;
            eleman->prev=temp;
            start->prev=eleman;

        }


    }


}
void bastanSil(){
    if(start==NULL){
        printf("silinecek eleman yok \n");
    }
    else{
        if(start->next==start){
            free(start);
            start=NULL;
        }
        else{
            temp=start;
            while(temp->next!=start){
               temp=temp->next;
            }
            temp2=start->next;
            temp2->prev=start;
            free(start);
            temp2->prev=temp;
            temp->next=temp2;

            start=temp2;
        }
    }



}
void sondanSil(){
    if(start==NULL){
        printf("silinecek eleman yok \n");
    }
    else{
        if(start->next==start){
            free(start);
            start=NULL;
        }
        else{
            temp=start;
            while(temp->next!=start){
               temp=temp->next;
            }
            temp2=temp->prev;
            temp2->next=temp;
            free(temp);
            temp2->next=start;
            start->prev=temp2;


            }
    }



}
int elemanAdeti(){
     int adet=0;
     if(start==NULL){
        return adet;
     }
     else{
    temp=start;
    while(temp->next!=start){
           adet++;
           temp=temp->next;
    }
adet++;
return adet;
}
}
int toplam(){
     int toplam=0;
     if(start==NULL){
        return toplam;
     }
     else{
    temp=start;
    while(temp->next!=start){
           toplam+=temp->data;
           temp=temp->next;
    }
    toplam+=temp->data;
    return toplam;
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
    printf("%d ",temp->data);

}
}

int main(){
    int sayi2 , secim;
    setlocale(LC_ALL,"Turkish");
    while(1){
    printf("\n *********  ÇİFT YÖNLÜ DAİRESEL BAĞLI LİSTE *******\n");
    printf("Başa eleman eklemek için 1 \n");
    printf("Sona eleman ekelemek için 2 \n");
    printf("Baştan eleman silmek için 3 \n");
    printf("Sondan eleman silmek için 4 \n ");
    printf("Eleman adeti için 5 \n");
    printf("verilerin toplamı için 6 \n");
    printf("Lütfen yapmak istediğiniz işlemi seçiniz \n");
    scanf("%d",&secim);
    switch(secim){
    case 1 : printf("Eklemek istediğiniz sayıyı giriniz \n");
             scanf("%d",&sayi2);
             basaEkle(sayi2);
             yazdir();
             break;

    case 2 : printf("Eklemek istediğiniz sayıyı giriniz \n");
             scanf("%d",&sayi2);
             sonaEkle(sayi2);
             yazdir();
             break;

    case 3 : bastanSil();
             yazdir();
             break;
    case 4 : sondanSil();
             yazdir();
             break;


   case 5 :  printf("%d",elemanAdeti());
             break;
   case 6 :
            printf("%d",toplam());
            break;
}
    }
}
