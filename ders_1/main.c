#include <stdio.h>
#include <stdlib.h>

struct n{
        int x;//Veriyi tutan alan
        struct n * next;//Bir sonraki düðümün adresini tutan pointer
};
typedef struct n node;// 'struct n' yerine sadece 'node' yazabilmek için

int main()
{
    node * root; // Baðlý listenin baþlangýç düðümünü gösteren pointer
    root = (node *)malloc(sizeof(node));//ilk kutuyu oluþturduk
    root ->x = 10; //Pointer'ýn gösterdiði bellek adresindeki x alanýna eriþ
    root -> next = (node *)malloc(sizeof(node));//yeni bir kutu oluþtu ve bunu ilk kutuya baðladý
    root -> next -> x = 20; //rootun gösterdiði kutunun nextinin x i
    root -> next -> next = (node *)malloc(sizeof(node));
    root -> next -> next -> x = 30;
    node * iter;
    iter = root;
    printf("%d\n", iter->x);
    iter = iter -> next;
    printf("%d", iter->x);
}


