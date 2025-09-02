#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

typedef struct node{
    int data;
    struct node *next;
}*Node;

typedef struct {
    Node head;
    int count;
}List;

List* initialize();
void insertFirst(List *L, int data);
void insertLast(List *L, int data);
void display(List *L);
void empty(List *L);

int main (void){
    List *L;
    L = initialize();

    // printf("Insert First Function:\n");

    // insertFirst(L, 2);
    // insertFirst(L, 4);
    // insertFirst(L, 6);
    // display(L);

    // printf("\n==========\n");

    // printf("Empty Function:\n");
    // empty(L);
    // display(L);

    // printf("\n==========\n");
    printf("Insert Last Function:\n");
    insertLast(L, 6);
    insertLast(L, 4);
    insertLast(L, 2);

    display(L);

    return 0;
}

List* initialize(){
    List *L;
    L = (List*)malloc(sizeof(List));
    L->head = NULL;
    L->count = 0;
    return L;
}

void empty(List *L){
    Node temp;
    while(L->head != NULL){
        temp = L->head;
        L->head = L->head->next;
        L->count--;
        free(temp);

    }
}

void insertFirst(List *L, int data){
    Node temp;
    temp = (Node)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = data;
        temp->next = L->head;
        L->head = temp;
        L->count++;
    }
}

void insertLast(List *L, int data){
    Node temp, *trav;
    for(trav = &L->head; *trav != NULL; trav = &(*trav)->next){}
    if(*trav == NULL){
        temp = (Node)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = data;
            temp->next = *trav;
            *trav = temp;
        }
        L->count++;
    } 
}


void display(List *L){
    Node trav;
    int x;
    if(L->head != NULL){
    printf("Head: ");
        for(trav = L->head; trav != NULL; trav=trav->next){
            printf("->");
            printf(" %d ", trav->data);
        }
        printf("\nTotal Number of Nodes: %d", L->count);
    }else{
        printf("The Linked List is Empty.");
    }

}