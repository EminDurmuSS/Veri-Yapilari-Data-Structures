#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct node {
    int data;
    struct node *right;
    struct node *left;
};
struct node *kokOlustur(int veri){
    struct node *root;
    root=(struct node *)malloc(sizeof(struct node));

    root->data=veri;
    root->left=NULL;
    root->right=NULL;

    return root ;
}

struct node *elemanEkle(struct node *root,int veri){
    if(root==NULL){
        root=kokOlustur(veri);

    }
    else{
        if(veri<(root->data)){
            root->left=elemanEkle(root->left,veri);
        }
        else{
            root->right=elemanEkle(root->right,veri);
        }

    }

    return root;
}
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}




int main(){
    setlocale(LC_ALL,"Turkish");
    printf("****Ağaç(trees) veri yapısı *****\n");
    struct node *eleman = NULL;

    int sayi;
    for(int i =0;i<7;i++){
        printf("sayı giriniz \n");
        scanf("%d",&sayi);
        eleman=elemanEkle(eleman,sayi);
    }
    printf("\n preorder :  ");
    preorder(eleman);

    printf("\n inorder : ");
    inorder(eleman);

    printf("\n postorder : ");
    postorder(eleman);


    return 0;
}
