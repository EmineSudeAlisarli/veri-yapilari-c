/*Kullanýcýdan bir kelime girmesini isteyen
ve bu kelimeyi, baðlý liste ile oluþturulmuþ
bir Stack (Yýðýn) veri yapýsý kullanarak ters
çeviren bir C programý yazýnýz.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct n{
    char kelime;
    struct n* next;
}node;
node* root = NULL;
void bastir(){
    node* iter= root;
    while(iter != NULL){
        printf(" %c", iter->kelime);
        iter = iter->next;
    }
}
void push(char kelime){
    node* temp = (node*)malloc(sizeof(node));
    if(temp == NULL){
        printf("Bellek hatasi!\n");
        return;
    }
    temp ->kelime = kelime;
    temp->next = root;
    root = temp;
}
int main()
{
    char kelime[30];
    printf("Bir kelime giriniz: ");
    scanf(" %s", kelime);
    for(int i = 0; i< strlen(kelime);i++){
        push(kelime[i]);
    }
    bastir();
    return 0;
}
