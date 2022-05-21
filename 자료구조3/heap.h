#ifndef HEAP_H
# define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct treeNode{
	int				weight;
	char			ch;
	struct treeNode	*left;
	struct treeNode	*right;
}treeNode;

typedef struct {
	treeNode	*ptree;
	char		ch;
	int			key;
}element;

typedef struct {
	element	heap[MAX_ELEMENT];
	int		heap_size;
}heapType;

heapType	*create(){
	return (heapType *)malloc(sizeof(heapType));
}

void	init(heapType *h){
	h->heap_size = 0;
}

void	insert_min_heap(heapType *h, element item){
	int	i = ++(h->heap_size);
	
	while (i != 1 && item.key < h->heap[i / 2].key){
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(heapType *h){
	int		parent, child;
	element	item, tmp;

	item = h->heap[1];
	tmp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size){
		if (child < h->heap_size && h->heap[child].key > h->heap[child + 1].key)
			child++;
		if (tmp.key < h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child += 2;
	}
	h->heap[parent] = tmp;
	return item;
}

treeNode	*make_tree(treeNode *left, treeNode *right){
	treeNode	*node = (treeNode *)malloc(sizeof(treeNode));
	node->left = left;
	node->right = right;
	return node;
}

void	destroy_tree(treeNode *root){
	if (!root) return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

int	is_leaf(treeNode *root){
	return (!(root->left) && !(root->right));
}

void	print_array(int codes[], int n){
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

void	print_codes(treeNode *root, int codes[], int top){
	if (root->left){
		codes[top] = 0;
		print_codes(root->left, codes, top + 1);
	}
	if (root->right){
		codes[top] = 1;
		print_codes(root->right, codes, top + 1);
	}
	if (is_leaf(root)){
		printf("%c: ", root->ch);
		print_array(codes, top);
	}
}

#endif