
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include "dLinkedList.h"

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
//Adds a new node to the front of a list, or if the list is currently empty sets it as the first node
dlList addAtFront(dlList usrList, int value){
    dlList newNode = malloc(sizeof(struct dlListStruct));
    newNode->data = value;
    newNode->prev = NULL;
    if (usrList == NULL){
        newNode->next = NULL;
        return newNode;
    }
    dlList ptr = usrList;
    if (ptr->prev != NULL) ptr = ptrToStart(usrList);
    newNode->next = ptr;
    return newNode;
}
//Adds a new node to the end of a list, or if the list is currently empty sets it as the first node
dlList addAtEnd(dlList usrList, int value){
    dlList newNode = malloc(sizeof(struct dlListStruct));
    newNode->data = value;
    newNode->next = NULL;
    if (usrList == NULL){
        newNode->prev = NULL;
        return newNode;
    }
    dlList ptr = usrList;
    if (ptr->next != NULL) ptr = ptrToEnd(usrList);
    newNode->prev = ptr;
    return newNode;
}
dlList removeAtFront(dlList);
dlList removeAtEnd(dlList);

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