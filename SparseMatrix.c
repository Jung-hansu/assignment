#include <stdio.h>

typedef struct {
	int	row;
	int	col;
	int	value;
}term;

void	transpose(term input[], term output[])
{
	int	m, n, v, i, j, p;
	m = input[0].row;
	n = input[0].col;
	v = input[0].value;
	output[0].row = n;
	output[0].col = m;
	output[0].value = v;
	if (v){
		p = 1;
		for (i = 0; i < n; i++)
			for (j = 1; j <= v; j++)
				if (input[j].col == i){
					output[p].row = input[j].col;
					output[p].col = input[j].row;
					output[p].value = input[j].value;
					p++;
				}
	}
}

int	main()
{
	term a[9];
	term b[9];
	FILE *fp1, *fp2;
	fp1 = fopen("input.txt", "r");
	for (int i = 0; i < 9; i++)
		fscanf(fp1, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);
	fclose(fp1);
	transpose(a,b);
	fp2 = fopen("output.txt","w");
	for (int i = 0; i < 9; i++)
		fprintf(fp2, "%d %d %d\n", b[i].row, b[i].col, b[i].value);
	fclose(fp2);
}