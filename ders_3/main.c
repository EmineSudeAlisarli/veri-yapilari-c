#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n * next;
};
typedef struct n node;

void ekle(node * iter){
    for(int i = 1; i<=6; i++){
        iter -> next = (node *)malloc(sizeof(node));
        iter = iter -> next;
        iter -> x = i*10;
        iter -> next = NULL;
    }
}

void bastir(node * iter){
    while(iter -> next != NULL){
        printf("%d\n", iter->x);
        iter = iter -> next;
    }
}

int main()
{
    node * root;
    root = (node *)malloc(sizeof(node));
    root -> x = 0;
    root -> next = NULL;
    ekle(root);
    bastir(root);

    node * iter;
    iter = root;
    for (int i = 0; i<3;i++){
        iter = iter -> next;
    }
    node * temp = (node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> x = 1587;

    printf("\n\n");
    bastir(root);
    return 0;
}
