#include "./maze.h"

void path(){
	int row, col, next_row, next_col, dir;
	int found = 0;
	element position;
	mark[1][1] = 1;
	top = 0;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;
	while (top > -1 && !found){
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		while (dir < 8 && !found){
			next_row = row + move[dir].x;
			next_col = col + move[dir].y;
			if (next_row == EXIT_ROW && next_col == EXIT_COL)
				found = 1;
			else if (!maze[next_row][next_col] && !mark[next_row][next_col]){
				mark[next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				push(position);
				row = next_row;
				col = next_col;
				dir = 0;
			}
			else
				++dir;
		}
	}
	if (found){
		printf("The path is:\n");
		printf("row col\n");
		for (int i = 0; i <= top; i++)
			printf("%2d%5d\n",stack[i].row, stack[i].col);
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
		printf("\n\nThe maze:\n");
		for (int i = 0; i <= top; i++)
			maze[stack[i].row][stack[i].col] = 2;
		maze[row][col] = 2;
		maze[EXIT_ROW][EXIT_COL] = 2;
		for (int i = 0; i < EXIT_ROW + 2; i++){
			for (int j = 0; j < EXIT_COL + 2; j++)
				printf("%d ",maze[i][j]);
			printf("\n");
		}
	}
	else printf("The maze does not have a path\n");
}

int main(){
	path();
	return 0;
}