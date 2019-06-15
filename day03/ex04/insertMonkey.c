#include <stdlib.h>
#include "header.h"

struct s_queue {
	struct s_node_ *first;
	struct s_node_ *last;
};

struct s_node_ {
	struct s_node **message;
	struct s_node_ *next;
};

struct s_queue *queueInit(void) {
	struct s_queue *new;

	if (!(new = (struct s_queue *)malloc(sizeof(struct s_queue))))
		return (NULL);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, struct s_node **message) {
	struct s_node_ *ptr;
	struct s_node_ *new;

	if (!(queue && message))
		return ;
	if (!(new = (struct s_node_ *)malloc(sizeof(struct s_node_))))
		return ;
	new->message = message;
	new->next = NULL;
	ptr = queue->first;
	if (!ptr)
	{
		queue->first = new;
		queue->last = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	queue->last = new;
}

struct s_node **dequeue(struct s_queue *queue) {
	struct s_node_ *a;
	struct s_node_ *b;
	void *message;

	if (!queue)
		return (NULL);
	if (!queue->first)
		return (NULL);
	a = queue->first;
	b = a->next;
	queue->first = b;
	if (!queue->first)
		queue->last = NULL;
	message = a->message;
	free(a);
	return (message);
}

struct s_node **peek(struct s_queue *queue) {
	if (!queue)
		return (NULL);
	if (!queue->first)
		return (NULL);
	return (queue->first->message);
}

int isEmpty(struct s_queue *queue) {
	if (!queue)
		return (1);
	return (queue->first == NULL);
}

int max(int a, int b) {
	return (a > b ? a : b);
}

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

int saveTheSequoia(struct s_node **root) {
	if (!*root)
		return (0);
	int swp = 0;
	while (saveTheSequoia(&(*root)->left));
	while (saveTheSequoia(&(*root)->right));
	if ((*root)->left && (*root)->left->value > (*root)->value) {
		swap(&(*root), &(*root)->left);
		swp += 1;
	}
	if ((*root)->right && (*root)->right->value > (*root)->value) {
		swap(&(*root), &(*root)->right);
		swp += 1;
	}
	if (swp) {
		saveTheSequoia(root);
		return (1);
	}
	return (swp);
}

void insertMonkey(struct s_node **root, struct s_node *monkey) {
	if (!*root)
		*root = monkey;
	else {
		struct s_queue *q = queueInit();
		enqueue(q, root);
		while (!isEmpty(q)) {
			struct s_node **node = dequeue(q);
			if (!*node) {
				*node = monkey;
				break ;
			}
			else {
				enqueue(q, &(*node)->left);
				enqueue(q, &(*node)->right);
			}
		}
		saveTheSequoia(root);
	}
}
