#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_
#include <stdlib.h>
/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------
/**
 *  Linked list representation -- R2 Curs2 (Slide 8)
 */
typedef struct ListNode
{
    Item elem;             // Stored node value
    struct ListNode *next; // link to next node
    struct ListNode *prev; // link to prev node
} ListNode;

/**
 *  Double linked list representation -- desen Curs 3 (Slide 19)
 */
typedef struct List
{
    ListNode *first; // link to the first node
    ListNode *last;  // link to the last node
} List;
// -----------------------------------------------------------------------------

/**
 * Create a new node
 *  [input]: Item
 *  [output]: List*
 */
ListNode *createNode(Item elem)
{
    // TODO: Cerinta 1a
    ListNode *node = malloc(sizeof(struct ListNode));
    node->elem = elem;
    node->next = node->prev = NULL;
    return node;
}

/**
 * Create a new (empty)  list  -- Silde-urile 13/14 Curs 2
 *  [input]: None
 *  [output]: List*
 */
List *createList(void)
{
    // TODO: Cerinta 1a
    List *list = malloc(sizeof(struct List));
    list->first = list->last = NULL;
    return list;
}
// -----------------------------------------------------------------------------

/**
 * Determines if the list is empty
 *  [input]: List*
 *  [output]: 1 - empty/ 0 - not empty
 */
int isEmpty(List *list)
{
    // TODO: Cerinta 1b
    if (list == NULL || list->first == NULL)
    {
        return 1;
    }
    return 0;
}
// -----------------------------------------------------------------------------

/**
 * Determines if a list contains a specified element
 *  [input]: List*, Item
 *  [output]: int (1 - contains/ 0 - not contains)
 */
int contains(List *list, Item elem)
{
    // TDOO: Cerinta 1c
    if (list == NULL)
    {
        return 0;
    }
    ListNode *iter = list->first;
    while (iter != NULL)
    {
        if (iter->elem == elem)
        {
            return 1;
        }
        iter = iter->next;
    }
    return 0;
}
// -----------------------------------------------------------------------------

/**
 * Insert a new element in the list at the specified position.
 * Note: Position numbering starts with the position at index zero
 *  [input]: List*, Item, int
 *  [output]: void
 */
void insertAt(List *list, Item elem, int pos)
{
    if (list == NULL)
        return;

    ListNode *node = createNode(elem);

    if (list->first == NULL)
    {
        list->first = list->last = node;
        return;
    }

    if (pos == 0)
    {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
        return;
    }

    ListNode *current = list->first;
    int currentPos = 0;

    while (current->next != NULL && currentPos < pos - 1)
    {
        current = current->next;
        currentPos++;
    }

    if (current->next == NULL && currentPos == pos - 1)
    {
        current->next = node;
        node->prev = current;
        list->last = node;
        return;
    }

    if (current->next != NULL)
    {
        node->next = current->next;
        node->prev = current;
        current->next->prev = node;
        current->next = node;
    }
    else
    {
        current->next = node;
        node->prev = current;
        list->last = node;
    }
}
// -----------------------------------------------------------------------------

/**
 * Delete the first element instance form a list.
 *  [input]: List*, Item
 *  [output]: void
 */
void deleteOnce(List *list, Item elem)
{
    // Guard against young player errors
    if (list == NULL)
        return;

    // TODO: Cerinta 1e
}
// -----------------------------------------------------------------------------

/**
 * Compute list length
 *  [input]: List*
 *  [output]: int
 */
int length(List *list)
{
    // Guard against young player errors
    if (list == NULL)
        return 0;

    // TODO: Cerinta 1f
    return 0;
}
// -----------------------------------------------------------------------------

/**
 * Destroy a list.
 *  [input]: List*
 *  [output]: void
 */
List *destroyList(List *list)
{
    // Guard against young player errors
    if (list == NULL)
        return NULL;

    // TODO: Cerinta 1g
    return NULL;
}
// -----------------------------------------------------------------------------

#endif //_DOUBLE_LINKED_LIST_H_
