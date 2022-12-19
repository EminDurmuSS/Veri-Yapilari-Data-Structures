#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// tek yönlü doğrusal bağlı liste uygulaması (öğrenci kayıt )


struct ogrenci{ // düğüm yapısı
    int no;
    char ad[40];
    int vize;
    int finalo;
    double ort;
    struct node *next;
};
typedef struct ogrenci node ; // struct öğrenci diyeceğimize node yi kullansın

node * ekle (node * head){
    system("cls");
    node *ogr=(node*)malloc(sizeof(node)); // düğüm tanımladık ve bellekte yer ayırdık
    printf("Öğrenci NO: ");
    scanf("%d",&ogr->no);
    printf("Adi : ");
    scanf("%s",&ogr->ad);
    printf("Vize : ");
    scanf("%d",&ogr->vize);
    printf("Final : ");
    scanf("%d",&ogr->finalo);
    printf("\n");
    ogr->ort =(ogr->vize) *0.4+ (ogr->finalo)*0.6;
    if(head==NULL){
        head=ogr;
        head->next=NULL;
        printf("Liste oluşturuldu ve ilk öğrenci kayıt edildi \n");
    }
    else{
        ogr->next=head;
        head=ogr;
        printf("Düğüm eklenildi \n ");
    }

    return head;
}
    node * sil(node * head){
    if(head==NULL){
        printf("Lite boş ,silinecek öğrenci yok \n");
        return head;
    }
    else{
        int ogrNo;
        printf("Öğrenci No: ");
        scanf("%d",&ogrNo);
        if(head->no==ogrNo && head->next==NULL){// dizide silinmek istenen eleman ilk düğümmü
            free(head);
            head->next=NULL;
            printf("Listede kalan son öğrenci silindi \n");

        }
        else if (head->no==ogrNo && head->next!=NULL){
                node *p=head->next;
                free(head);
                head=p;
                printf("%d numaralı öğrenci silindi \n",ogrNo);
    }
    else{
            node * p=head;
            node *q=head;
            while(p->next!=NULL){
                if(p->no==ogrNo){
                    q->next=p->next;
                    free(p);
                    printf("%d numaralı öğrenci silindi \n",ogrNo);
                    break;
                }
                q=p;
                p=p->next;
            }

    }
    }
    return head;
}
node * yazdir(node *head){
    system("cls");
    if(head==NULL){
        printf("Lite boş \n");
    }
    else{
        node *p=head;
        while(p!=NULL){
            printf(" \n *************************\n");
            printf("No : %d ad : %s : vize %d Final %d Ortalama %.2f  \n ", p->no,p->ad,p->finali,p->ort);
            p=p->next;
        }


    }
    return head;
}
node * enyuksekPuan(node *head){
        system("cls");
    int buyukOrt=head->ort;
    node *buyukDugum=head;

    if(head==NULL){
        printf("Liste boş !!! \n");
    }
    else{
        node *p=head;
        while(p!=NULL){
            if(buyukOrt < p->ort){
                buyukOrt=p->ort;
                buyukDugum=p;
            }
            p=p->next;
        }
        printf("En yüksek ortalama olan öğrenci bilgileri : \n");
        printf("no : %d \n",buyukDugum->no);
        printf("no : %s \n",buyukDugum->ad);
        printf("no : %d \n",buyukDugum->vize);
        printf("no : %d \n",buyukDugum->finali);

    }
    return head;
}
int main(){
    setlocale(LC_ALL,"Turkish");
    int secim;
    node *head=NULL;
    while(1){
        printf("Tek yönlü doğrusal bağlı liste ile öğrenci kayıt uygulaması \n");
        printf("1--> ekle \n");
        printf("2--> sil \n");
        printf("3--> yazdir \n");
        printf("4--> en yüksek ortalaması olan öğrenciyi göster  \n");
        printf("0--> çıkış \n");
        printf("Lütfen seçiminizi yapınız \n");
        int secim;
        scanf("%d",&secim);
        switch(secim){
        case 1: head = ekle(head);
            break;
        case 2: head = sil(head);
            break;
        case 3: head = yazdir(head);
            break;
        case 4: head =ekle(head);
            break;
        case 5 : head =enyuksekPuan(head);
            break;
        case 0: exit(0);
            break;
        default :   printf("Hatali secim!! \n");

        }


    }

    return 0;
}
