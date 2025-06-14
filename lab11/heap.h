#ifndef __HEAP_H__
#define __HEAP_H__
/*
*	Created by Nan Mihai on 14.05.2024
*	Copyright (c) 2024 Nan Mihai. All rights reserved.
*	Laborator - Structuri de date si algoritmi
*	Facultatea de Automatica si Calculatoare
*	Anul Universitar 2023-2024, Seria CD
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 	10000
#define SIZE 	200

typedef struct hpair {
	int node, cost;
} HPair;

typedef HPair Type;

typedef struct heap {
	Type vector[MAX];
	int size;
	int capacity;
	int (*compare_func)(const void*, const void*);
} *Heap;

/**
*	Inițializează cu 0 dimensiunea heap-ului și atribuie valoarea pentru
* funcția generică de comparare.
*	De asemenea, alocă și memorie pentru structura heap.
**/
Heap initHeap(int (*compare_func) (const void*, const void*));

/**
*	Funcții auxiliare care realizează "cernerea" pentru a menține proprie-
* tățile structurii de date.
**/
Heap siftDown(Heap h, int index);
Heap siftUp(Heap h, int index);
Heap swapAndSiftDown(Heap h, int parent, int child);

/**
*	Introduce un element în heap și realizează "cernerea" pentru asigura-
* rea respectării proprietăților de maxHeap.
**/
Heap insertHeap(Heap h, Type element);

/**
*	Extrage elementul minim din heap (rădăcina heap-ului).
**/
Type extractMin(Heap h);

/**
*	Funcție care dealoca memoria alocată pentru structura de date.
**/
Heap freeHeap(Heap h);

/**
* Funcție care verifică dacă un heap este gol
**/
int isEmptyHeap(Heap h);

#endif /* HEAP_H */
