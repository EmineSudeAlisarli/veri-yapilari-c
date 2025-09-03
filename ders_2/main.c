#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n * next;
};
typedef struct n node;

void ekle(node*r){
    for(int i=1; i<=6; i++){
        r -> next = (node*)malloc(sizeof(node));
        r = r -> next;
        r-> x = i*10;
        r -> next = NULL;
    }
}

void bastir(node * r){
    int i = 0;
    while(r -> next != NULL){
        i++;
        printf("%d. eleman: %d\n", i, r -> x);
        r = r -> next;
    }
}

int main()
{
    node * root;
    root = (node*)malloc(sizeof(node));
    root -> x = 0;
    root -> next = NULL;

    ekle(root); //rootun gösterdigi yerden baslicak.
    bastir(root); //rootun gosterdigi degerden baslicak.
    return 0;
}
