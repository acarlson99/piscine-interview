#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct s_node *createBST(int *arr, int n) {
	int i = n / 2;
	if (n <= 0)
		return (NULL);
	struct s_node *node = malloc(sizeof(struct s_node));
	node->value = arr[i];
	node->left = createBST(arr, i);
	if (i <= 0)
		node->right = NULL;
	else
		node->right = createBST(arr + 1 + i, n - i - 1);
	return (node);
}
