#ifndef STACK_H
# define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
	int				data;
	struct treeNode	*left;
	struct treeNode	*right;
} treeNode;

typedef struct stackNode{
	treeNode *data;
	struct stackNode *link;
}stackNode;

void push(stackNode **top, treeNode *item){
	stackNode *tmp = (stackNode *)malloc(sizeof(stackNode));
 
	tmp->data = item;
	tmp->link = *top;
	*top = tmp;
}

treeNode	*pop(stackNode **top){
	treeNode *item;
	stackNode *tmp = *top;

	item = tmp->data;
	*top = (*top)->link;
	free(tmp);
	return item;
}

treeNode *peek(stackNode *top){
	if (!top){
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	return top->data;
}

int	is_Empty(stackNode *top){
	return (top == NULL);
}

#endif