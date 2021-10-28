all:	basicDriver.c
	clear
	gcc dLinkedList.c basicDriver.c -Wall
debug:	basicDriver.c
	clear
	gcc dLinkedList.c basicDriver.c -Wall -ggdb