#include <stdio.h>
#include <stdlib.h>

struct n{
        int x;//Veriyi tutan alan
        struct n * next;//Bir sonraki dügümün adresini tutan pointer
};
typedef struct n node;// 'struct n' yerine sadece 'node' yazabilmek icin

int main()
{
    node * root; // Bagli listenin baslangic dügümünü gösteren pointer
    root = (node *)malloc(sizeof(node));//ilk kutuyu olusturduk
    root ->x = 10; //Pointer'in gösterdigi bellek adresindeki x alanina eris

    root -> next = (node *)malloc(sizeof(node));//yeni bir kutu oluþtu ve bunu ilk kutuya baðladý
    root -> next -> x = 20; //rootun gösterdiði kutunun nextinin x i

    root -> next -> next = (node *)malloc(sizeof(node));
    root -> next -> next -> x = 30;
    root -> next -> next -> next = NULL;

    node * iter;
    iter = root;
    printf("%d\n", iter->x);
    iter = iter -> next;
    printf("%d\n\n\n", iter->x);

    iter = root;
    int i = 0;
    while(iter != NULL){//listenin icinde gezme
        i++;
        printf("%d. eleman: %d\n",i, iter -> x);
        iter = iter -> next;
    }
    for(i = 0;i<5;i++){//listeye yeni nodelar ekleme ve her node için değer verme.
        iter -> next = (node *)malloc(sizeof(node)); //yeni kutu oluusturduk
        iter = iter -> next //artık o kutuya erisim var.
        iter -> x = i*10;
        iter -> next = NULL;//son kutu NULL degerine esit.
    }
}


