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
//List deletePos(List L, int pos);
//int locate(List L, int data);
//List insertSorted(List L, int data);
//void display(List L);

int main (void){
    List L = initList(L);
	int data, pos;
	
	L = insertPos(L, 1, 0);
	L = insertPos(L, 3, 1);
	L = insertPos(L, 2, 2);
	L = insertPos(L, 5, 3);
	L = insertPos(L, 4, 2);
	L = insertPos(L, 6, 3);

	
    return 0;
}


List initList(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int pos) {
	int x;
    if (pos <= L.count || L.count < MAX) {
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


