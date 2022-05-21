#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
	char			data;
	struct treeNode	*left;
	struct treeNode	*right;
} treeNode;

void	preorder(treeNode *ptr){
	if(ptr){
		printf("%c", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void	inorder(treeNode *ptr){
	if(ptr){
		inorder(ptr->left);
		printf("%c", ptr->data);
		inorder(ptr->right);
	}
}

void	postorder(treeNode *ptr){
	if(ptr){
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%c", ptr->data);
	}
}

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
	leftNode->data = 2 * (parent->data - 64) + 64;
	rightNode->data = 2 * (parent->data - 64) + 65;
	leftNode = createTree(leftNode, level - 1);
	rightNode = createTree(rightNode, level - 1);
	return parent;
}

int	main(){
	treeNode	*root = (treeNode *)malloc(sizeof(treeNode));
	root->data = 'A';
	root = createTree(root, 3);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	return 0;
}