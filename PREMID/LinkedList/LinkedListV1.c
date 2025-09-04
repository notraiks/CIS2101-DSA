#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

typedef struct node{
    int data;
    struct node *next;
}*List;

void insertFirst(List *L, int data);
void insertLast(List *L, int data);
void display(List L);

int main (void){

    List L = NULL;

    insertFirst(&L, 2);
    insertFirst(&L, 4);
    insertFirst(&L, 6);

    insertLast(&L, 8);
    insertLast(&L, 9);
    insertLast(&L, 10);

    display(L);

    return 0;
}

void insertFirst(List *L, int data){
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = data;
        temp->next = *L;
        *L = temp;
    }
}

void insertLast(List *L, int data){
    List *trav, temp;
    temp = (List)malloc(sizeof(struct node));
    if(temp != NULL){
        for(trav = L; *trav != NULL; trav = &(*trav)->next){}
        if(*trav == NULL){
            temp->data = data;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void display(List L){
    List trav;
    printf("Node: ");
    for(trav = L; trav != NULL; trav = trav->next){
        printf(" -> ");
        printf(" %d ", trav->data);
    }
    printf("\n");
}

