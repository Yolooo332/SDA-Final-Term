#ifndef __LIST_H__
#define __LIST_H__
/*
*	Created by Nan Mihai on 14.05.2024
*	Copyright (c) 2024 Nan Mihai. All rights reserved.
*	Laborator - Structuri de date si algoritmi
*	Facultatea de Automatica si Calculatoare
*	Anul Universitar 2023-2024, Seria CD
*/
#include <stdio.h>
#include <stdlib.h>	

typedef struct pair {
	int u, v, cost;
} Pair;

typedef Pair V;

typedef struct list {
	V data;
	struct list *prev, *next;
}*List;

/*
*	Funcție care va returna o listă cu un singur nod cu valoarea data
*/
List initList(V data);

/*
*	Funcție care adaugă un nod cu valoarea data la începutul lui list
*/
List addFirst(List list, V data);

/*
*	Funcție care adaugă un nod cu valoarea data la finalul lui list
*/
List addLast(List list, V data);

/*
*	Funcție care elimină prima apariție a valorii data din lista list
*/
List deleteItem(List list, V data);

/*
*	Funcție care dealocă memoria alocată pentru o listă
*/
List freeList(List list);

#endif /* LIST_H */
