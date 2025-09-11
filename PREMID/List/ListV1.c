#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initList(List L);
List insertPos(List L, int data, int pos);
List insertSorted(List L, int data);
List deletePos(List L, int pos);
int locate(List L, int data);
void display(List L);

int main (void){
    List L;
	L = initList(L);
	int data, pos;
	
	L = insertPos(L, 1, 0);
	L = insertPos(L, 3, 1);
	L = insertPos(L, 2, 2);
	L = insertPos(L, 5, 3);
	L = insertPos(L, 4, 2);
	L = insertPos(L, 6, 3);

	printf("Insert Position Function: ");
	display (L);

	printf("===========\n");
	L = deletePos(L, 5);
	printf("Delete Value from a Specific Position: ");
	display (L);

	printf("===========\n");
	printf("Sort Array");
	

    return 0;
}


List initList(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int pos) {
	int x;
    if (pos <= L.count && L.count < MAX) {
    	for(x = L.count; x > pos; x--){
    		L.elem[x] = L.elem[x - 1];
		}
		L.elem[pos] = data;
		L.count++;
		return L;
    } else {
        printf("Invalid position or list is full, cannot insert element.\n");
    }
}

List insertSorted(List L, int data){

	int x, pos;
	if(L.count < MAX){
		for(x = 0; x < L.count && L.elem[x] < data; x++){}
		pos = x;
		for(x = L.count; x > pos; x--){
			L.elem[x] = L.elem[x - 1];
		}
		L.elem[pos] = data;
		L.count++;
		return L;
	} else {
		printf("List is full, cannot insert element. \n");
	}
}

List deletePos(List L, int pos){
	int x;
	if(pos <= L.count && L.count < MAX){
		for(x = pos; x > L.count; x++){
			L.elem[pos] = L.elem[x + 1];
		}
		L.count--;
		return L;
	} else {
		printf("Invalid position or list is empty, cannot insert element. \n");
	}
}

int locate(List L, int data){
	int x;
	for(x = 0; x < MAX && L.elem[x] != data; x++){}
	return (L.elem[x] != data) ? 1 : 0;
}


void display(List L){
	int x;
	for(x=0;x<L.count;x++){
		printf("%d ", L.elem[x]);
	}
	printf("\n");
}

