
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "dLinkedList.h"
#include <limits.h>

//Returns a pointer to the last node in the list
static dlList ptrToEnd(dlList);
//Returns a pointer to the first node in the list
static dlList ptrToStart(dlList);

//Node data structure. May need another field to store typing.
struct dlListStruct{
    int data;
    struct dlListStruct* next;
    struct dlListStruct* prev;
};
//Initializes a list to Null;
dlList createList(){
    return NULL;
}
//Adds a new node to the front of a list, or if the list is currently empty sets it as the first node, and returns location of first node
dlList addAtFront(dlList usrList, int value){
    dlList newNode = malloc(sizeof(struct dlListStruct));
    newNode->data = value;
    newNode->prev = NULL;
    if (usrList == NULL){
        newNode->next = NULL;
        return newNode;
    }
    dlList ptr = ptrToStart(usrList);
    newNode->next = ptr;
    ptr->prev = newNode;
    return newNode;
}
//Adds a new node to the end of a list, or if the list is currently empty sets it as the first node, and returns location of last node
dlList addAtEnd(dlList usrList, int value){
    dlList newNode = malloc(sizeof(struct dlListStruct));
    newNode->data = value;
    newNode->next = NULL;
    if (usrList == NULL){
        newNode->prev = NULL;
        return newNode;
    }
    dlList ptr = ptrToEnd(usrList);
    newNode->prev = ptr;
    ptr->next = newNode;
    return newNode;
}
//Removes the first node and returns the location of the new first node
dlList removeAtFront(dlList usrList){
    if (usrList != NULL){
        dlList ptr = ptrToStart(usrList);
        if (ptr != NULL) ptr = ptr->next;
        if (ptr != NULL) free(ptr->prev);
        return ptr;
    }
    return NULL;
}
//Removes the last node and returns the location of the new last node
dlList removeAtEnd(dlList usrList){
    if (usrList != NULL){
        dlList ptr = ptrToEnd(usrList);
        if (ptr != NULL) ptr = ptr->prev;
        if (ptr != NULL) free(ptr->next);
        return ptr;
    }
    return NULL;
}
//Prints out the entire list starting from the front
void printListFtoB(dlList usrList){
    if(usrList != NULL){
        dlList ptr = ptrToStart(usrList);
        while (ptr->next != NULL){
            printf("%d ", getData(ptr));
            ptr=ptr->next;
        }
    }
}
//Prints out the entire list strating from the end
void printListBtoF(dlList usrList){
    if(usrList != NULL){
        dlList ptr = ptrToEnd(usrList);
        while (ptr->prev != NULL){ 
            printf("%d ", getData(ptr));
            ptr = ptr->prev;
        }
    }
}
//Returns current items data, or INT_MIN if the list is NULL
int getData(dlList usrList){
    if(usrList != NULL) return usrList->data;
    return INT_MIN;
}
static dlList ptrToEnd(dlList usrList){
    if (usrList == NULL){
        return NULL;
    }
    dlList ptr = usrList;
    while(ptr->next != NULL) ptr=ptr->next;
    return ptr;
}
static dlList ptrToStart(dlList usrList){
    if (usrList == NULL){
        return NULL;
    }
    dlList ptr = usrList;
    while(ptr->prev != NULL) ptr=ptr->prev;
    return ptr;
}