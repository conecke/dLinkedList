/*
Attempted Implementation of a doubly linked list data structure, started on 10/27/2021 by ceck
*/
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <stdlib.h>




typedef struct dlListStruct *dlList;
dlList createList();
dlList addAtFront(dlList, int);
dlList addAtEnd(dlList, int);
dlList removeAtFront(dlList);
dlList removeAtEnd(dlList);




#endif