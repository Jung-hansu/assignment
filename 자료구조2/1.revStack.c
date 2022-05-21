#include "./stack.h"

void revStack(stackNode **top){
	stackNode *top1 = NULL;
	stackNode *top2 = NULL;
	
	while(*top)
		push(pop(top), &top1);
	while(top1)
		push(pop(&top1), &top2);
	while(top2)
		push(pop(&top2), top);
}

int main(){
	stackNode *top = NULL;

	for (int i = 1; i <= 3; i++)
		push(i, &top);
	printf("Before stack:\t");
	printStack(top);
	revStack(&top);
	printf("After stack:\t");
	printStack(top);
	return 0;
}
