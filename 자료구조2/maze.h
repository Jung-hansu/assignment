#ifndef MAZE_H
# define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#define EXIT_COL 15
#define EXIT_ROW 14
#define MAX_STACK_SIZE 100

typedef struct{
	short int x;
	short int y;
}offsets;

typedef struct{
	short int row;
	short int col;
	short int dir;
}element;

offsets move[8] = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};
element stack[MAX_STACK_SIZE];
int top;
int mark[EXIT_ROW + 2][EXIT_COL + 2];
int maze[EXIT_ROW + 2][EXIT_COL + 2] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
										{1,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,1},
										{1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,1,1},
										{1,0,1,1,1,0,0,1,0,1,1,1,0,1,0,1,1},
										{1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1},
										{1,0,1,0,0,0,1,1,1,0,1,0,1,1,1,0,1},
										{1,0,1,0,0,1,1,0,1,0,1,0,0,0,0,0,1},
										{1,0,1,1,1,1,0,0,1,0,0,1,0,1,1,0,1},
										{1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1},
										{1,0,1,1,0,1,0,0,0,1,0,0,1,1,0,0,1},
										{1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1},
										{1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1},
										{1,1,0,0,0,1,0,0,1,1,1,0,0,0,0,0,1},
										{1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,0,1},
										{1,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1},
										{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

int is_empty(){
    return (top == -1);
}

int is_full(){
    return (top == MAX_STACK_SIZE - 1);
}

void push(element item){
    if (is_full()){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else stack[++top] = item;
}

element pop(){
    if (is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}

element peek(){
    if (is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

#endif