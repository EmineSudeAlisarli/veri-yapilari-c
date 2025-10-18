#include <stdio.h>
#include <stdlib.h>
struct n{
    int data;
    struct n* next;
};
typedef struct n node;
void bastir(node*root){
    while(root != NULL){
        printf("%d->",root->data);
        root = root -> next;
    }
    printf("\n");
}
int pop(node*root){
    int rvalue;
    if(root == NULL){
        printf("Bagli liste bostur!");
        return-1;
    }
    node*iter = root;
    if(iter->next == NULL){
        rvalue = root->data;
        free(root);
        return rvalue;
    }
    while(iter->next->next != NULL){
        iter = iter ->next;
    }
    node*temp = iter->next;
    rvalue = temp->data;
    free(temp);
    iter->next = NULL;
    return rvalue;
}
node* push(node* root,int a){
    if (root == NULL){
        root = (node*)malloc(sizeof(node));
        root->data=a;
        root->next = NULL;
        return root;
    }
    node*iter=root;

    while(iter->next!= NULL){
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp ->data = a;
    temp-> next = NULL;
    iter->next = temp;
    return root;
}
int main()
{
    node* s = NULL;
    s = push(s,10);
    s = push(s,20);
    s = push(s,30);
    s = push(s,40);
    s = push(s,50);
    bastir(s);
    printf("%d->",pop(s));
    printf("%d->",pop(s));
    printf("%d->",pop(s));
    printf("\n");
    bastir(s);

    return 0;
}
