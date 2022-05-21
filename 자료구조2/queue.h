#ifndef QUEUE_H
# define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int	id;
	int	arrival_time;
	int	service_time;
}element;

typedef struct QNode{
    element data;
    struct QNode *link;
} QNode;

typedef struct{
    QNode *front, *rear;
} QType;

QType *createQueue(){
    QType *Q;
    Q = (QType *)malloc(sizeof(QType));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

int is_empty(QType *Q){
    return (Q->front == NULL);
}

void enQueue(QType *Q, element item){
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    if (Q->front == NULL){
        Q->front = newNode;
        Q->rear = newNode;
    }
    else{
        Q->rear->link = newNode;
        Q->rear = newNode;
    }
}

element deQueue(QType *Q){
    QNode *old = Q->front;
    element item = {0, 0, 0};
    if (is_empty(Q)) return item;
    else{
        item = old->data;
        Q->front = Q->front->link;
        if (Q->front == NULL)
            Q->rear = NULL;
        free(old);
        return item;
    }
}

#endif