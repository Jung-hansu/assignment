#include "stack.h"

treeNode	*createTree(treeNode *parent, int level){
	if(level == 1){
		parent->left = NULL;
		parent->right = NULL;
		return parent;
	}
	treeNode	*leftNode = (treeNode *)malloc(sizeof(treeNode));
	treeNode	*rightNode = (treeNode *)malloc(sizeof(treeNode));
	parent->left = leftNode;
	parent->right = rightNode;
	leftNode->data = parent->data * 2;
	rightNode->data = parent->data * 2 + 1;
	leftNode = createTree(leftNode, level - 1);
	rightNode = createTree(rightNode, level - 1);
	return parent;
}

void	postOrderIterative(treeNode *root){
	if (root == NULL)
		return ;

	stackNode *s1 = NULL;
	stackNode *s2 = NULL;

	push(&s1, root);
	treeNode *node;

	while (!is_Empty(s1)){
		node = pop(&s1);
		push(&s2, node);

		if (node->left) push(&s1, node->left);
		if (node->right) push(&s1, node->right);
	}
	while (!is_Empty(s2)){
		node = pop(&s2);
		printf("%d", node->data);
	}
}

int	main(){
	treeNode *root = (treeNode *)malloc(sizeof(treeNode));
	root->data = 1;
	root = createTree(root, 3);
	postOrderIterative(root);
	return 0;
}