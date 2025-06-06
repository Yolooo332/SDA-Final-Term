#include "graph.h"

// TODO - Implementati functiile pentru un graf neorientat
Graph initGraph(int nrVarfuri)
{
    Graph g = malloc(sizeof(struct graph));
    if (!g)
    {
        return NULL;
    }

    g->V = nrVarfuri;

    g->adjLists = malloc(nrVarfuri * sizeof(struct list));
    if (!g->adjLists)
    {
        free(g);
        return NULL;
    }

    for (int i = 0; i < nrVarfuri; i++)
    {
        g->adjLists[i] = NULL;
    }

    g->dist = calloc(nrVarfuri, sizeof(int));
    if (!g->dist)
    {
        free(g->adjLists);
        free(g);
        return NULL;
    }
    return g;
}

Graph addEdge(Graph g, int u, int v)
{
    g->adjLists[u] = addLast(g->adjLists[u], v);
    g->adjLists[v] = addLast(g->adjLists[v], u);
    return g;
}

Graph deleteVertex(Graph g, int v)
{
    List current = g->adjLists[v];
    while (current)
    {
        g->adjLists[current->data] = deleteItem(g->adjLists[current->data], v);
        current = current->next;
    }

    free(g->adjLists[v]);
    g->adjLists[v] = NULL;
    return g;
}

int getDegree(Graph g, int v)
{
    int degree = 0;
    List current = g->adjLists[v];
    while (current)
    {
        degree++;
        current = current->next;
    }
    return degree;
}

// Functie care va deseneaza graful
void drawGraph(Graph g, char *name)
{
    int i, j;
    FILE *stream;
    char *buffer;
    List tmp;

    if (g == NULL || name == NULL)
        return;
    stream = fopen(name, "w");
    fprintf(stream, "graph G {\n");
    fprintf(stream, "    node [fontname=\"Arial\", shape=circle, style=filled, fillcolor=yellow];\n");
    for (i = 0; i < g->V; i++)
    {
        tmp = g->adjLists[i];
        while (tmp != NULL)
        {
            if (tmp->data > i)
                fprintf(stream, "    %d -- %d;\n", i, tmp->data);
            tmp = tmp->next;
        }
    }
    fprintf(stream, "}\n");
    fclose(stream);
    buffer = (char *)malloc(SIZE * sizeof(char));
    sprintf(buffer, "dot %s | neato -n -Tpng -o graph.png", name);
    system(buffer);
    free(buffer);
}
