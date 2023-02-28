#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "typedefs.h"

struct LinkedListNode
{
    void *data;
    struct LinkedListNode *next;
    struct LinkedListNode *prev;
};

struct LinkedList
{
    struct LinkedListNode *head;
    struct LinkedListNode *last;
    int size;
};

struct LinkedList *linkedListNew();

struct LinkedListNode *linkedListNodeNew(void *value);

void linkedListAppend(struct LinkedList *list, void *value);

void *linkedListGet(struct LinkedList *list, int index);

void linkedListDispose(struct LinkedList *list);

#endif
