#include "./stack.h"

int	prec(char op){
	switch (op){
		case '(': case ')':
			return 0;
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
	}
	return -1;
}

element evalPost(char *exp){
	int			op1, op2, val;
	int			len = strlen(exp);
	char		symbol;
	stackNode	*top = NULL;

	for (int i = 0; i < len; i++){
		symbol = exp[i];
		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/'){
			val = symbol - '0';
			push(val, &top);
		}
		else{
			op2 = pop(&top);
			op1 = pop(&top);
			switch (symbol){
				case '+':
					push(op1 + op2, &top);
					break;
				case '-':
					push(op1 - op2, &top);
					break;
				case '*':
					push(op1 * op2, &top);
					break;
				case '/':
					push(op1 / op2, &top);
					break;
			}
		}
	}
	return pop(&top);
}

void in_to_post(char exp[], char tmp[]){
	int			i = 0, j = 0;
	char		ch, top_op;
	int			len = strlen(exp);
	stackNode	*top = NULL;

	for (;i < len; i++){
		ch = exp[i];
		switch(ch){
			case '+': case '-': case '*': case '/':
				while (!is_Empty(top) && (prec(ch) <= prec(peek(top)))){
					tmp[j++] = peek(top);
					printf("%c", pop(&top));
				}
				push(ch, &top);
				break;
			case '(':
				push(ch, &top);
				break;
			case ')':
				top_op = pop(&top);
				while (top_op != '('){
					tmp[j++] = top_op;
					printf("%c", top_op);
					top_op = pop(&top);
				}
				break;
			default:
				tmp[j++] = ch;
				printf("%c", ch);
				break;
		}
	}
	while (!is_Empty(top)){
		tmp[j++] = peek(top);
		printf("%c", pop(&top));
	}
	tmp[j] = 0;
}

int	main(){
	char	exp[] = "2-6/3*6+4";
	char	tmp[10];

	printf("infix\t\tpostfix\t\tresult");
	printf("\n---------------------------------------\n");
	printf("%s\t",exp);
	in_to_post(exp, tmp);
	printf("\t%d\n", evalPost(tmp));
	return 0;
}