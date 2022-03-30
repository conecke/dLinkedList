/*
Attempted Implementation of a doubly linked list data structure, started on 10/27/2021 by ceck
*/
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <stdlib.h>

typedef struct dlNodeStruct *dlNode;
typedef struct dlListStruct *dlList;
//Initializes a list to Null;
dlList createList();
//Adds a new node to the front of a list, or if the list is currently empty sets it as the first node, and returns location of first node
dlList addAtFront(dlList, int);
//Adds a new node to the end of a list, or if the list is currently empty sets it as the first node, and returns location of last node
dlList addAtEnd(dlList, int);
//Removes the first node and returns the location of the new first node
dlList removeAtFront(dlList);
//Removes the last node and returns the location of the new last node
dlList removeAtEnd(dlList);
//Prints out the entire list starting from the front
void printListFtoB(dlList);
//Prints out the entire list strating from the end
void printListBtoF(dlList);
//Returns size of list
int getSize(dlList);
//Sorts list using bubble sort and returns location of new first element
dlList bubbleSort(dlList);

#endif