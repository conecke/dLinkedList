
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "dLinkedList.h"
#include <limits.h>
#include <stdbool.h>

static dlList swapNodeF(dlNode, dlList);
static dlList swapNodeB(dlNode, dlList); 
static bool isSorted(dlList);

//Node data structure
struct dlNodeStruct{
    int data;
    struct dlNodeStruct* next;
    struct dlNodeStruct* prev;
};
//Header data structure
struct dlListStruct{
    int count;
    struct dlNodeStruct* head;
    struct dlNodeStruct* tail;
};
//Initializes a list to Null
dlList createList(){
    dlList outList = malloc(sizeof(struct dlListStruct));
    outList->count = 0;
    outList->head = NULL;
    outList->tail = NULL;
    return outList;
}
//Adds a new node to the front of a list, or if the list is currently empty sets it as the first node, and returns location of first node
dlList addAtFront(dlList usrList, int value){
    dlNode newNode = malloc(sizeof(struct dlNodeStruct));
    newNode->data = value;
    newNode->prev = NULL;
    if (usrList->count == 0){
        newNode->next = NULL;
        usrList->count++;
        usrList->head = newNode;
        usrList->tail = newNode;
        return usrList;
    }
    newNode->next = usrList->head;
    usrList->head->prev = newNode;
    usrList->head = newNode;
    usrList->count++;
    return usrList;
}
//Adds a new node to the end of a list, or if the list is currently empty sets it as the first node, and returns location of last node
dlList addAtEnd(dlList usrList, int value){
    dlNode newNode = malloc(sizeof(struct dlNodeStruct));
    newNode->data = value;
    newNode->next = NULL;
    if (usrList->count == 0){
        newNode->prev = NULL;
        usrList->count++;
        usrList->head = newNode;
        usrList->tail = newNode;
        return usrList;
    }
    newNode->prev = usrList->tail;
    usrList->tail->next = newNode;
    usrList->tail = newNode;
    usrList->count++;
    return usrList;
}
//Removes the first node and returns the location of the new first node
dlList removeAtFront(dlList usrList){
    if (usrList->count != 0){
        dlNode ptr = usrList->head;
        if (ptr != NULL) ptr = ptr->next;
        if (ptr != NULL){
            usrList->count--;
            free(ptr->prev);
        } 
        usrList->head = ptr;
        return usrList;
    }
    return NULL;
}
//Removes the last node and returns the location of the new last node
dlList removeAtEnd(dlList usrList){
    if (usrList->count != 0){
        dlNode ptr = usrList->tail;
        if (ptr != NULL) ptr = ptr->prev;
        if (ptr != NULL){
            usrList->count--;
            free(ptr->next);
        } 
        usrList->tail = ptr;
        return usrList;
    }
    return NULL;
}
//Prints out the entire list starting from the front
void printListFtoB(dlList usrList){
    if(usrList->count != 0){
        dlNode ptr = usrList->head;
        while (ptr!= NULL){
            printf("%d ", ptr->data);
            ptr=ptr->next;
        }
    }
}
//Prints out the entire list strating from the end
void printListBtoF(dlList usrList){
    if(usrList->count != 0){
        dlNode ptr = usrList->tail;
        while (ptr != NULL){ 
            printf("%d ", ptr->data);
            ptr = ptr->prev;
        }
    }
}
//Returns lists size, or INT_MIN if the list is NULL
int getSize(dlList usrList){
    return usrList==NULL?INT_MIN:usrList->count;
}
//Sorts list using bubble sort
dlList bubbleSort(dlList usrList){
    #ifdef MYDBG
    printf("isSorted: %s", isSorted(usrList)?"True\n":"False\n");
    #endif
    dlNode ptr = usrList->head;
    while (!isSorted(usrList)){
        if(ptr->next != NULL && ptr->data > ptr->next->data){
            swapNodeF(ptr,usrList);
        }
        ptr = ptr->next;
        if (ptr == NULL) ptr = usrList->head;
    }
    return usrList;
}
//Swaps the current node with the node in front
static dlList swapNodeF(dlNode usrNode, dlList usrList){
    if (usrNode != NULL){
        dlNode n1 = usrNode;
        dlNode nf = n1->next;
        dlNode nb = n1->prev;
        if (nf == NULL) return usrList;;
        n1->prev = nf;
        n1->next = nf->next;
        if (nf -> next != NULL) nf->next->prev = n1;
        nf->next = n1;
        nf->prev = nb;
        nb->next = nf;
    }
    return usrList;    
}
//Swaps the node with the node behind
static dlList swapNodeB(dlNode usrNode, dlList usrList){
    if (usrNode != NULL){
        dlNode n1 = usrNode;
        dlNode n2 = n1->next;
        dlNode nb = n1->prev;
        if (nb == NULL) return usrList;
        n1->next = nb;
        n1->prev = nb->prev;
        if (nb->prev != NULL) nb->prev->next = n1;
        nb->next = n2;
        nb->prev = n1;
        n2->prev = nb;
    }
    return usrList;
}
static bool isSorted(dlList usrList){
    dlNode ptr = usrList->head;
    while (ptr != usrList->tail){
        if (ptr->data > ptr->next->data) return false;
        ptr=ptr->next;
    }
    return true;
}