#ifndef _INT_QUEUE_H
#define _INT_QUEUE_H

#include <stdlib.h>

#define INT_QUEUE_MAX_LENGTH 50

typedef struct Int_Queue {
    int values[INT_QUEUE_MAX_LENGTH];
    int front;
    int rear;
} Int_Queue;

Int_Queue *new_int_queue();

int is_empty_int_queue(Int_Queue *queue);

int int_queue_insert(Int_Queue *queue, int value);

int int_queue_pop(Int_Queue *queue, int *dest);

int del_int_queue(Int_Queue *queue);

#endif