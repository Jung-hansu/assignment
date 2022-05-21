#include <stdio.h>

typedef struct{
	int	coef;
	int	exp;
}polynomial;
polynomial	terms[14];
int	avail = 0;

int	compare(polynomial A[], polynomial B[], int a, int b)
{
	if (A[a].exp > B[b].exp) return 1;
	else if (A[a].exp == B[b].exp) return 0;
	else return -1;
}

int	main()
{
	polynomial	A[3] = {{3,14},{2,8},{1,0}};
	polynomial	B[3] = {{8,14},{-3,10},{10,6}};
	int	a = 0, b = 0;
	while (a < 3 || b < 3)
	{
		if (compare(A,B,a,b) == 1)
			terms[avail++] = A[a++];
		else if (compare(A,B,a,b) == -1)
			terms[avail++] = B[b++];
		else
		{
			terms[avail].coef = A[a].coef + B[b++].coef;
			terms[avail++].exp = A[a++].exp;
		}			
	}
	while (a < 3)
		terms[avail++] = A[a++];
	while (b < 3)
		terms[avail++] = B[b++];
	printf("A(x) + B(x)의 결과\n");
	for (int i = 0; i < avail; i++)
		printf("coef: %d exp: %d\n",terms[i].coef, terms[i].exp);
}