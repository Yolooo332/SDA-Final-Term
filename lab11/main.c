/*
*	Created by Nan Mihai on 14.05.2024
*	Copyright (c) 2024 Nan Mihai. All rights reserved.
*	Laborator - Structuri de date si algoritmi
*	Facultatea de Automatica si Calculatoare
*	Anul Universitar 2023-2024, Seria CD
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"
#include "heap.h"

int compare(const void *a, const void *b) {
	HPair *pa, *pb;
	pa = (HPair*) a;
	pb = (HPair*) b;
	return pb->cost - pa->cost;
}

/*
* start -> nodul de start
* end -> nodul destinație (folosit pentru afișarea drumului)
* distances -> vector ce a fost deja alocat în care vom reține costurile 
               drumurilor minime
*/
void Dijkstra(Graph g, int start, int end, int *distances) {
	Heap h = initHeap(compare);
	HPair pair;
	// Exemplu de folosire pentru heap
	// pair.node = v;
	// pair.cost = cost;
	// h = insertHeap(h, pair);
	// TODO 1
	h = freeHeap(h);
}

/*
* start -> nodul de start din care pornim aplicarea algoritmului
* cost -> costul pentru arborele minim de acoperire
* Funcția întoarce o listă cu muchii 
*/
List Prim(Graph g, int start, int *cost) {
	List result = NULL;
	*cost = 0;
	Heap h = initHeap(compare);
	HPair pair;
	pair.node = start;
	pair.cost = 0;
	h = insertHeap(h, pair);
	// TODO 2
	h = freeHeap(h);
	return result;
}

int main() {
	freopen("test2.in", "r", stdin);
	int V, type, i, x, y, M, cost;
	scanf("%d %d", &V, &type);
	Graph graph = initGraph(V, type);
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &cost);
		graph = insertEdge(graph, x, y, cost);
	}
	printGraph(graph);
	drawGraph(graph, "graph1.dot");

	int *distances = malloc(V * sizeof(int));
	Dijkstra(graph, 1, 5, distances);
	for (i = 1; i < V; i++) {
		printf("%d -> %d ; ", i, distances[i]);
	}
	printf("\n\n");
	free(distances);

	cost = 0;
	List AMA = Prim(graph, 1, &cost);
	printf("Cost: %d\n", cost);
	List iter = AMA;
	while (iter) {
		printf("(%d - %d), cost = %d\n", iter->data.u, iter->data.v, iter->data.cost);
		iter = iter->next;
	}
	AMA = freeList(AMA);


	graph = freeGraph(graph);
	return 0;
}