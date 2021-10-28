#include "dLinkedList.h"
#include <stdio.h>

int main(void){

    dlList list = createList();
    printListFtoB(list);
    list = addAtFront(list, 4);
    addAtFront(list, 2);
    addAtEnd(list, 6);
    printListBtoF(list); printf("\n");
    printListFtoB(list); printf("\n");
    //printf("%d\n", getData(list));
    addAtEnd(list, 8);
    addAtEnd(list,10);
    addAtFront(list, 0);
    printListFtoB(list); printf("\n");
    return 0;
}