#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int pos);
void deletePos(EPtr L, int pos);
int locate(EPtr L, int data);
int retrieve(EPtr L, int pos);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main (void){
    EPtr L = (EPtr)malloc(sizeof(Etype));
    initialize(L);

	insertPos(L, 1, 0);
	insertPos(L, 3, 1);
	insertPos(L, 2, 2);
	insertPos(L, 5, 3);
	insertPos(L, 4, 2);
	insertPos(L, 6, 3);

    printf("Insert Position Function: ");
	display (L);


    return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int pos) {
	int x;
    if (pos <= L->count && L->count < MAX) {
    	for(x = L->count; x > pos; x--){
    		L->elem[x] = L->elem[x - 1];
		}
		L->elem[pos] = data;
		L->count++;
    } else {
        printf("Invalid position or list is full, cannot insert element.\n");
    }
}

void display(EPtr L){
	int x;
	for(x=0;x<L->count;x++){
		printf("%d ", L->elem[x]);
	}
	printf("\n");
}
