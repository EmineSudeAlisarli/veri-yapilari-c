#include <stdio.h>
#include <stdlib.h>

struct n{
        int x;//Veriyi tutan alan
        struct n * next;//Bir sonraki d�g�m�n adresini tutan pointer
};
typedef struct n node;// 'struct n' yerine sadece 'node' yazabilmek icin

int main()
{
    node * root; // Bagli listenin baslangic d�g�m�n� g�steren pointer
    root = (node *)malloc(sizeof(node));//ilk kutuyu olusturduk
    root ->x = 10; //Pointer'in g�sterdigi bellek adresindeki x alanina eris

    root -> next = (node *)malloc(sizeof(node));//yeni bir kutu olu�tu ve bunu ilk kutuya ba�lad�
    root -> next -> x = 20; //rootun g�sterdi�i kutunun nextinin x i

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
    while(iter != NULL){
        i++;
        printf("%d. eleman: %d\n",i, iter -> x);
        iter = iter -> next;
    }

}


