#include "heap.h"

void	huffman_tree(int freq[], char ch_list[], int n){
	int			i;
	treeNode	*node, *x;
	heapType	*heap;
	element		e, e1, e2;
	int			codes[100];
	int			top = 0;

	heap = create();
	init(heap);
	for (i = 0; i < n; i++){
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap, e);
	}
	for (i = 1; i < n; i++){
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d + %d -> %d\n", e1.key, e2.key, e.key);
		insert_min_heap(heap, e);
	}
	e = delete_min_heap(heap);
	print_codes(e.ptree, codes, top);
	destroy_tree(e.ptree);
	free(heap);
}

int	main(){
	char	ch_list[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int		freq[] = {45, 13, 12, 16, 9, 5};
	huffman_tree(freq, ch_list, 6);
	return 0;
}