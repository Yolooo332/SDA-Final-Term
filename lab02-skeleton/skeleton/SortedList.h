#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <stdlib.h>
#include <assert.h>

/*
    IMPORTANT!

    As we stick to pure C, we cannot use templates. We will just asume
    some type T was previously defined.
*/

// -----------------------------------------------------------------------------

typedef struct node
{
    T value;
    struct node *next;
} TNode, *TSortedList;

// TODO : Cerința 1 & Cerința 2

TSortedList create(T value)
{
    // TODO (se va completa la Cerința 2)
    TSortedList list = malloc(sizeof(struct node));
    if (list == NULL)
    {
        return list;
    }
    list->value = value;
    list->next = NULL;
    return list;
}

int isEmpty(TSortedList list)
{
    return (list == NULL) ? 1 : 0;
}

int contains(TSortedList list, T value)
{
    TSortedList iter = list;
    while (iter != NULL)
    {
        if (iter->value == value)
        {
            return 1;
        }
        iter = iter->next;
    }
    return 0;
    // for (iter = list; iter != NULL; iter = iter->next)
    // {
    //     if (iter->value == value)
    //     {
    //         return 1;
    //     }
    // }
    // return 0;
}

TSortedList insertFront(TSortedList head, T value)
{
    TSortedList node = create(value);
    node->next = head;
    return node;
}

TSortedList insert(TSortedList head, T value)
{
    if (head == NULL)
    {
        return create(value);
    }

    if (head->value > value)
    {
        return insertFront(head, value);
    }

    TSortedList iter = head;
    while (iter->next != NULL && iter->next->value <= value)
    {
        iter = iter->next;
    }

    TSortedList node = create(value);
    node->next = iter->next;
    iter->next = node;
    return head;
}

TSortedList removeFront(TSortedList list)
{
    TSortedList temp;
    if (list == NULL)
    {
        return list;
    }
    temp = list;
    list = list->next;
    free(temp);
    return list;
}

TSortedList deleteOnce(TSortedList list, T value)
{
    TSortedList prev, iter;
    if (list == NULL)
    {
        return list;
    }
    if (list->value == value)
    {
        return removeFront(list);
    }
    if (contains(list, value) == 0)
    {
        return list;
    }
    prev = list;
    iter = list->next;
    while (iter != NULL)
    {
        if (iter->value == value)
        {
            prev->next = iter->next;
            free(iter);
            return list;
        }
        prev = iter;
        iter = iter->next;
    }
    return list;
}

long length(TSortedList head)
{
    if (head == NULL)
    {
        return head;
    }
    return 1 + length(head->next);
}

T getNth(TSortedList list, int N)
{
    TSortedList iter = list;
    for (int i = 1; i < N && iter != NULL; i++)
    {
        iter = iter->next;
    }
    return iter->value;
}

freeTSortedList(TSortedList list)
{
    TSortedList temp;
    while (list != NULL)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
    return NULL;
}

#endif
