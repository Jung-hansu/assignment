#include <stdio.h>

typedef struct polynomial{
	int	coef;
	int	exp;
	struct polynomial *next;
}polynomial;
int	terms[15] = {0};

int	main()
{
	polynomial A2 = {1,0,NULL}, A1 = {2,8,&A2}, A = {3,14,&A1};
	polynomial B2 = {10,6,NULL}, B1 = {-3,10,&B2}, B = {8,14,&B1};
	polynomial *tmp1 = &A;
	polynomial *tmp2 = &B;
	while(tmp1)
	{
		terms[tmp1->exp] = tmp1->coef;
		tmp1 = tmp1->next;
	}
	while(tmp2)
	{
		terms[tmp2->exp] -= tmp2->coef;
		tmp2 = tmp2->next;
	}
	printf("A(x) - B(x)의 결과\n");
	for (int i = 14; i >= 0; i--)
	{
		if (terms[i])
			printf("coef: %d exp: %d\n", terms[i], i);
	}
}