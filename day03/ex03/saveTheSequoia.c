#include "header.h"

void swap(struct s_node **a, struct s_node **b) {
	struct s_node *tmp = *a;
	struct s_node *left = (*b)->left;
	struct s_node *right = (*b)->right;

	*a = *b;
	if (tmp->left == (*b)) {
		(*b)->left = tmp;
		(*b)->right = tmp->right;
	}
	else {
		(*b)->left = tmp->left;
		(*b)->right = tmp;
	}
	tmp->left = left;
	tmp->right = right;
}

void saveTheSequoia(struct s_node **root) {
	if (!*root)
		return ;
	int swp = 0;
	if ((*root)->left && (*root)->left->value > (*root)->value) {
		swap(&(*root), &(*root)->left);
		swp = 1;
	}
	if ((*root)->right && (*root)->right->value > (*root)->value) {
		swap(&(*root), &(*root)->right);
		swp = 1;
	}
	saveTheSequoia(&(*root)->left);
	saveTheSequoia(&(*root)->right);
	if (swp)
		saveTheSequoia(root);
}
