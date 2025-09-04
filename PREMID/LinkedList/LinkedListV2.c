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
// void insertPosV1(List *L, int data, int idx);
void insertPosV2(List *L, int data, int idx);
void deleteFirst(List *L);
void display(List *L);
void empty(List *L);

int main (void){
    List *L;
    L = initialize();

    printf("Insert First Function:\n");

    insertFirst(L, 2);
    insertFirst(L, 4);
    insertFirst(L, 6);
    display(L);

    printf("\n==========\n");

    printf("Empty Function:\n");
    empty(L);
    display(L);

    printf("\n==========\n");
    printf("Insert Last Function:\n");
    insertLast(L, 2);
    insertLast(L, 4);
    insertLast(L, 6);
    display(L);

    printf("\n==========\n");
    printf("Insert in a Position Function:\n");
    // insertPosV1(L, 24, 2);
    insertPosV2(L, 1, 0);
    insertPosV2(L, 8, 4);
    insertPosV2(L, 5, 3);
    display(L);

    printf("\n==========\n");
    printf("Delete First Function:\n");
    deleteFirst(L);
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

// void insertPosV1(List *L, int data, int idx){
//     Node temp, *trav;
//     int x;
//     for(x = 0, trav = &L->head; *trav != NULL && x  < L->count && x != idx; trav = &(*trav)->next, x++){}
//     if(x == idx){
//         temp = (Node)malloc(sizeof(struct node));
//         if(temp != NULL){
//             temp->data = data;
//             temp->next = *trav;
//             *trav = temp;
//         }
//         L->count++;
//     }
// }

void insertPosV2(List *L, int data, int idx){
    int x;
    Node temp, *trav;
    if(idx == 0){
        insertFirst(L, data);
    }else if(idx == L->count){
        insertLast(L, data);
    }else{
        for(x = 0, trav = &L->head; *trav != NULL && x  < L->count && x != idx ; trav = &(*trav)->next, x++){}
        if(x == idx){
            temp = (Node)malloc(sizeof(struct node));
            if(temp != NULL){
                temp->data = data;
                temp->next = *trav;
                *trav = temp;
            }
            L->count++;
        }   
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

void deleteFirst(List *L){
    Node temp;
    temp = L->head;
    L->head = L->head->next;
    L->count--;
    free(temp);
}

void deleteLast(List *L){
    Node *trav, *trav2, temp;
    for(trav = &L->head, trav = &L->head->next; *trav != NULL && *trav2 = NULL; trav = &(*trav)->next, trav = &(*trav)->next){}
    if(*trav2 == NULL){
        temp = *trav;
        *trav2 =

    }
}