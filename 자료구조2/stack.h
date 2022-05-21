#ifndef STACK_H
# define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct stackNode{
	element data;
	struct stackNode *link;
}stackNode;

void push(element item, stackNode **top){
	stackNode *tmp = (stackNode *)malloc(sizeof(stackNode));
 
	tmp->data = item;
	tmp->link = *top;
	*top = tmp;
}

element	pop(stackNode **top){
	element item;
	stackNode *tmp = *top;

	item = tmp->data;
	*top = (*top)->link;
	free(tmp);
	return item;
}

element peek(stackNode *top){
	if (!top){
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	return top->data;
}

int	is_Empty(stackNode *top){
	return (top == NULL);
}

void printStack(stackNode *top){
	stackNode *p = top;
	printf(" STACK [ ");
	while (p){
		printf("%d ", p->data);
		p = p->link;
	}
	printf("]\n");
}

#endif