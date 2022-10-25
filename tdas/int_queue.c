#include "int_queue.h"

Int_Queue *new_int_queue() {
    Int_Queue *new_queue = (Int_Queue*)malloc(sizeof(Int_Queue));
    
    if (!new_queue)
        return NULL;
    
    new_queue->front = 0;
    new_queue->rear = 0;
}

int is_empty_int_queue(Int_Queue *queue) {
    return queue->front == queue->rear;
}

int int_queue_insert(Int_Queue *queue, int value) {
    if (queue->rear == INT_QUEUE_MAX_LENGTH - 1) {
        if (queue->front == 0)
            return -1;
        queue->rear = -1;
    }
    queue->values[queue->rear++] = value;
    return 0;
}

int int_queue_pop(Int_Queue *queue, int *dest) {
    if (is_empty_int_queue(queue))
        return -1;
    *dest = queue->values[queue->front++];
    return 0;
}

int del_int_queue(Int_Queue *queue) {
    if (!queue)
        return 1;

    free(queue);

    return 0;
}
