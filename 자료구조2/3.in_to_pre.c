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

void in_to_post(char exp[], char tmp[]){
	int			i = 0, j = 0;
	char		ch, top_op;
	int			len = strlen(exp);
	stackNode	*top = NULL;

	for (;i < len; i++){
		ch = exp[i];
		switch(ch){
			case '+': case '-': case '*': case '/':
				while (!is_Empty(top) && (prec(ch) <= prec(peek(top))))
					tmp[j++] = pop(&top);
				push(ch, &top);
				break;
			case '(':
				push(ch, &top);
				break;
			case ')':
				top_op = pop(&top);
				while (top_op != '('){
					tmp[j++] = top_op;
					top_op = pop(&top);
				}
				break;
			default:
				tmp[j++] = ch;
				break;
		}
	}
	while (!is_Empty(top))
		tmp[j++] = pop(&top);
	tmp[j] = 0;
}

void revInfix(char exp[], char tmp[]){
	strcpy(tmp, exp);
	strrev(tmp);
	for(int i = 0; tmp[i]; i++){
		if (tmp[i] == ')') tmp[i] = '(';
		else if (tmp[i] == '(') tmp[i] = ')';
	}
}

void in_to_pre(char exp[], char tmp[]){
	revInfix(exp, tmp);
	in_to_post(tmp, tmp);
	strrev(tmp);
}

int	main(){
	char	exp[] = "(3-4/2)*(6/3-1)";
	char	tmp[16];

	printf("infix\t\t\tprefix");
	printf("\n------------------------------------\n");
	in_to_pre(exp, tmp);
	printf("%s\t\t%s", exp, tmp);
	return 0;
}