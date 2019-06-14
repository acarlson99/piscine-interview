#include "header.h"

void swap(struct s_node **a, struct s_node **b) {
	struct s_node *tmp;
	tmp = (*a)->left;
	(*a)->left = (*b)->left;
	(*b)->left = tmp;

	tmp = (*a)->right;
	(*a)->right = (*b)->right;
	(*b)->right = tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdio.h>
void saveTheSequoia(struct s_node **root) {
	printf("%d\n", (*root)->value);
	printf("%d\n", (*root)->left->value);
	printf("%d\n\n", (*root)->right->value);

	swap(root, &(*root)->left);

	printf("%d\n", (*root)->value);
	printf("%d\n", (*root)->left->value);
	printf("%d\n", (*root)->right->value);
}
