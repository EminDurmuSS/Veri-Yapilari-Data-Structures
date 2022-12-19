#include <stdio.h>
#include <stdlib.h>
int a[27];
int h(int x){ // modunu al demek
        return x%27; // mod 27
}
int indis;

int put (int k,int v){ // hash tablosuna veri koyan fonksiyon
        while(a[h(k)]!=-1){
                k++;
        }
        a[h(k)]=v;          // k= modunu almak istediğimiz sayı v içine atacağımız değer

}
int get(int k){  //verdiğim parametrenin modunu al dizinin içine koyup değerini getir
    return a[h(k)];
}
void bastir(){
    printf("\n");
    for(int i=0;i<27;i++){
         printf("%d ",a[i]);
}
}
int main(){
    for(int i=0;i<27;i++){
        a[i]=-1;
    }

    put(10,10640099470);
    put(1,1210505049);
    put(28,31313131);
    put(55,696969);
    printf("%d\n",get(10));
    printf("%d\n",get(1));
    printf("%d\n",get(100));
    bastir();
    return 0;
}
