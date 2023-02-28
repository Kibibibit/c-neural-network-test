#include <stdlib.h>
#include "typedefs.h"
#include "linked_list.h"

struct LinkedList *linkedListNew()
{
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    list->size = 0;
    list->head = NULL;
    list->last = NULL;
    return list;
};

struct LinkedListNode *linkedListNodeNew(void *value)
{
    struct LinkedListNode *node = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void linkedListAppend(struct LinkedList *list, void *value)
{

    struct LinkedListNode *node = linkedListNodeNew(value);
    if (list->head == NULL)
    {
        list->head = node;
        list->last = node;
    }
    else
    {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }
    list->size += 1;
}

void *linkedListGet(struct LinkedList *list, int index)
{
    int at = 0;
    int forward = 1;
    struct LinkedListNode *currentNode = list->head;
    if (index > list->size / 2)
    {
        at = list->size - 1;
        forward = -1;
        currentNode = list->last;
    }
    while (at != index)
    {
        if (forward == 1)
        {
            currentNode = currentNode->next;
        }
        else
        {
            currentNode = currentNode->prev;
        }
        at += forward;
    }
    return currentNode->data;
}
    

void linkedListDispose(struct LinkedList *list)
{
    struct LinkedListNode *currentNode = list->head;
    struct LinkedListNode *prevNode = currentNode;
    while (currentNode != NULL)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
        free(prevNode);
    }
    free(list);
}
