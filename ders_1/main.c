#include <stdio.h>
#include <stdlib.h>

struct n{
        int x;//Veriyi tutan alan
        struct n * next;//Bir sonraki d���m�n adresini tutan pointer
};
typedef struct n node;// 'struct n' yerine sadece 'node' yazabilmek i�in

int main()
{
    node * root; // Ba�l� listenin ba�lang�� d���m�n� g�steren pointer
    root = (node *)malloc(sizeof(node));//ilk kutuyu olu�turduk
    root ->x = 10; //Pointer'�n g�sterdi�i bellek adresindeki x alan�na eri�
    root -> next = (node *)malloc(sizeof(node));//yeni bir kutu olu�tu ve bunu ilk kutuya ba�lad�
    root -> next -> x = 20; //rootun g�sterdi�i kutunun nextinin x i
    root -> next -> next = (node *)malloc(sizeof(node));
    root -> next -> next -> x = 30;
    node * iter;
    iter = root;
    printf("%d\n", iter->x);
    iter = iter -> next;
    printf("%d", iter->x);
}


