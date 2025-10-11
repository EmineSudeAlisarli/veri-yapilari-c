//cift yonlu bagli liste
#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n * next;
    struct n* prev;
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
    if (r == NULL){ // Link list bosta
        r = (node*)malloc(sizeof(node));
        r -> next = NULL;
        r->prev =NULL;
        r -> x = sayi;
        return r;
    }
    if ((r -> x) > sayi){ //Link list boþ deðil ama ilk elemandan küçük ise
            //root deðiþiyor
            node * temp = (node*)malloc(sizeof(node));
            temp -> x = sayi;
            temp -> next = r;
            r->prev = temp;
            temp->prev = NULL;
            return temp;
    }
    node * iter = r;
    while (iter->next != NULL && iter->next->x < sayi){
        iter = iter->next;
    }
    node * temp = (node*)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp->prev = iter;
    if(temp->next != NULL){
        temp->next->prev = temp;
    }
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
        root->prev=NULL;
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
    if(iter ->next != NULL){
        iter ->next->next->prev = iter;
    }
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
    root = silme(root, 50);
    root = silme(root, 4);
    root = silme(root, 450);
    bastir(root);

    return 0;
}

