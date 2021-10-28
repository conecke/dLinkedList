#include "dLinkedList.h"
#include <stdio.h>

int main(void){

    dlList list = createList();
    printListFtoB(list);
    addAtFront(list, 4);
    addAtFront(list, 2);
    addAtEnd(list, 6);
    printListBtoF(list); printf("\n");
    printListFtoB(list); printf("\n");
    printf("Size: %d\n", getSize(list));
    addAtEnd(list,10);
    addAtEnd(list,8);
    addAtFront(list, 0);
    addAtEnd(list,7);
    printListFtoB(list); printf("\n");
    bubbleSort(list); 
    printListFtoB(list);
    return 0;
}