#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n * next;
};
typedef struct n node;

void bastir(node * iter){
    while(iter != NULL){
        printf("%d\n", iter->x);
        iter = iter -> next;
    }
    printf("\n");
}

node * sirali_ekle(node * r, int sayi){
    if (r == NULL){ // Link list boþsa
        r = (node*)malloc(sizeof(node));
        r -> next = NULL;
        r -> x = sayi;
        return r;
    }
    if ((r -> x) > sayi){ //Link list boþ deðil ama ilk elemandan küçük ise
            //root deðiþiyor
            node * temp = (node*)malloc(sizeof(node));
            temp -> x = sayi;
            temp -> next = r;
            return temp;
    }
    node * iter = r;
    while (iter->next != NULL && iter->next->x < sayi){
        iter = iter->next;
    }
    node * temp = (node*)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> x = sayi;
    return r;
}

node * silme(node * root, int deger){
    if (root == NULL){
        printf("Liste bos.");
        return NULL;
    }
    node * iter = root;
    node * temp;
    if (root -> x == deger){
        temp = root;
        root = temp -> next;
        free(temp);
        return root;
    }
    while(iter -> next != NULL && iter -> next -> x != deger){
        iter = iter -> next;
    }
    if (iter->next == NULL){
        printf("Sayi bulunamadi.");
        return root;
    }
    temp = iter -> next;
    iter -> next = iter -> next -> next;
    free(temp);
    return root;
}

int main()
{
    node * root;
    root = NULL;

    root = sirali_ekle(root, 400);
    root = sirali_ekle(root, 40);
    root = sirali_ekle(root, 4);
    root = sirali_ekle(root, 450);
    root = sirali_ekle(root, 50);
    bastir(root);

    return 0;
}
