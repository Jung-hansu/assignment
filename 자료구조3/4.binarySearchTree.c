#include <stdio.h>
#include <stdlib.h>

// typedef struct thread_tree{
// 	char				data;
// 	struct thread_tree	*left_child;
// 	struct thread_tree	*right_child;
// 	short int			left_thread;
// 	short int			right_thread;
// }thread_tree;

// thread_tree	in_succ(thread_tree *ptr){
// 	if (ptr->right_thread)
// 		return ptr->right_child;
// 	else{
// 		ptr = ptr->right_child;
// 		while (!ptr->left_thread)
// 			ptr = ptr->left_child;
// 		return ptr;
// 	}
// }

// void	inorder(thread_tree *root){
// 	thread_tree	*ptr;

// 	ptr = root;
// 	while (!ptr->left_thread)
// 		ptr = ptr->left_child;
// 	while (ptr != root){
// 		printf("%c", ptr->data);
// 		ptr = in_succ(ptr);
// 	}
// }

// void	insert_right(thread_tree *parent, thread_tree *child){
// 	thread_tree	*tmp;

// 	child->right_child = parent->right_child;
// 	child->right_thread = parent->right_thread;
// 	child->left_child = parent;
// 	child->left_thread = TRUE;
// 	parent->right_child = child;
// 	parent->right_thread = FALSE;
// 	if (!child->right_thread){
// 		tmp = in_succ(child);
// 		tmp->left_child = child;
// 	}
// }

// void	insert_left(thread_tree *parent, thread_tree *child){
// 	thread_tree	*tmp;

// 	child->left_child = parent->left_child;
// 	child->left_thread = parent->left_thread;
// 	child->right_child = parent;
// 	child->right_thread = TRUE;
// 	parent->left_child = child;
// 	parent->left_thread = FALSE;
// 	if (!child->left_thread){
// 		tmp = in_succ(child);
// 		tmp->right_child = child;
// 	}
// }

typedef struct treeNode{
	int				key;
	struct treeNode	*left;
	struct treeNode	*right;
}treeNode;

treeNode	*search(treeNode *node, int key){
	if (!node) return 0;
	if (key == node->key)
		return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

treeNode	*new_node(int item){
	treeNode	*tmp = (treeNode *)malloc(sizeof(treeNode));
	tmp->key = item;
	tmp->left = tmp->right = 0;
	return tmp;
}

treeNode	*insert_node(treeNode *node, int key){
	if (!node) return new_node(key);
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	else
		printf("\n 이미 같은 키가 있습니다.\n");
	return node;
}

int main(){
	int key[] = {23, 18, 2, 16, 4, 10, 5, 39, 26, 15};
	treeNode	*root;
	for (int i = 0; i < 6; i++)
		root = insert_node(root, key[i]);
	printf("%d %d %d %d %d\n", root->key, root->right->key, root->left->key, root->right->right->key, root->right->left->key);
}

//segfault 뜹니당