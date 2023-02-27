#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct LinkedListNode
{
    void *data;
    struct LinkedListNode *next;
    struct LinkedListNode *prev;
    unsigned long data_size;
};

struct LinkedList
{
    struct LinkedListNode *head;
    struct LinkedListNode *last;
    int size;
};

struct LinkedList *linkedListNew();

struct LinkedListNode *linkedListNodeNew(void *value, unsigned long data_size);

void linkedListAppend(struct LinkedList *list, void *value, unsigned long data_size);

void *linkedListGet(struct LinkedList *list, int index);

void linkedListNodeDispose(struct LinkedListNode *node);

void linkedListDispose(struct LinkedList *list);

#endif
