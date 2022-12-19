#include <stdio.h>
#include <stdlib.h>
// düğüm oluşturuyorum
/* şöyle bi düğüm olutşturdum oluşturduğum şu düğümde bi yapı oluşturuyorum öncelikle daha sonra bu oluşturduğum yapının
dahilinde diğer elemanı göstermesi için bir pointer oluşturuyorum*/
struct dugum{
    int veri;
    struct dugum * gosterici;
};

int main()
{   struct dugum * bir;
    bir =(struct dugum *)malloc(sizeof(struct dugum)); // hafızada yer ayırtıyorum

    struct dugum * iki;
    iki= (struct dugum *)malloc(sizeof(struct dugum));

    struct dugum * uc; // şöyle pointerla bi düğüm oluşturuyorum oluşturduğum bu düğümede pointer olduğu için mallocla hafızada yer ayırtıyorum ki bilgi işliyebileyim
    uc = (struct dugum *)malloc(sizeof(struct dugum));
// adres mantığını unutma yukarıda bak oluşturdum adres göstergesi var alttada tekrardan yeni adreslerini verdim
   bir->veri=11;
    bir->gosterici=iki;

    iki->veri=20;
    iki->gosterici=uc;

    uc->veri=25;
    uc->gosterici=NULL;

    printf("%d %d %d",bir->veri,iki->veri,uc->veri);
    // aşağıdaki örnektede olduğu gibi manası aynı 

  /*  (*bir).veri=20;
    (*bir).gosterici=iki;

    printf("%d",(*bir).veri);*/


    return 0;
}
