#include <stdlib.h>
#include"linked_list.h"

struct LinkedList *linkedListNew()
{
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    list->size = 0;
    list->head = NULL;
    list->last = NULL;
    return list;
};

struct LinkedListNode *linkedListNodeNew(void *value, unsigned long data_size)
{
    struct LinkedListNode *node = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
    node->data = malloc(data_size);
    int i;
    /// Allow for variably sized for each element, regardless of datatype
    for (i = 0; i < data_size; i++)
    {
        *(char *)(node->data + i) = *(char *)(value + i);
    }
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void linkedListAppend(struct LinkedList *list, void *value, unsigned long data_size)
{

    struct LinkedListNode *node = linkedListNodeNew(value, data_size);
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

void linkedListNodeDispose(struct LinkedListNode *node)
{
    free(node->data);
    free(node);
}

void linkedListDispose(struct LinkedList *list)
{
    struct LinkedListNode *currentNode = list->head;
    struct LinkedListNode *prevNode = currentNode;
    while (currentNode != NULL)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
        linkedListNodeDispose(prevNode);
    }
    free(list);
}
