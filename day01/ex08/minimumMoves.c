#include <string.h>
#include <stdlib.h>
#include "header.h"

struct s_info {
	struct s_node *node;
	int n;
};

struct s_node_ {
	struct s_info *info;
	struct s_node_ *next;
};

struct s_queue {
	struct s_node_ *first;
	struct s_node_ *last;
};

struct s_queue *queueInit(void) {
	struct s_queue *new;

	if (!(new = (struct s_queue *)malloc(sizeof(struct s_queue))))
		return (NULL);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, struct s_info *info) {
	struct s_node_ *ptr;
	struct s_node_ *new;
	struct s_info *info_dup;

	if (!(queue && info))
		return ;
	if (!(new = (struct s_node_ *)malloc(sizeof(struct s_node_))))
		return ;
	info_dup = malloc(sizeof(*info_dup));
	memcpy(info_dup, info, sizeof(*info));
	new->info = info_dup;
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

struct s_info *dequeue(struct s_queue *queue) {
	struct s_node_ *a;
	struct s_node_ *b;
	void *info;

	if (!queue)
		return (NULL);
	if (!queue->first)
		return (NULL);
	a = queue->first;
	b = a->next;
	queue->first = b;
	if (!queue->first)
		queue->last = NULL;
	info = a->info;
	free(a);
	return (info);
}

struct s_info *peek(struct s_queue *queue) {
	if (!queue)
		return (NULL);
	if (!queue->first)
		return (NULL);
	return (queue->first->info);
}

int isEmpty(struct s_queue *queue) {
	if (!queue)
		return (1);
	return (queue->first == NULL);
}

int minimumMoves(struct s_node *begin) {
	struct s_queue *q = queueInit();

	enqueue(q, &(struct s_info){begin, 0});
	while (!isEmpty(q)) {
		struct s_info *info = dequeue(q);
		int n = info->n;
		if (info->node->isFinal) {
			free(info);
			return (n);
		}
		if (info->node->next)
			enqueue(q, &(struct s_info){info->node->next, n + 1});
		if (info->node->random)
			enqueue(q, &(struct s_info){info->node->random, n + 1});
	}
	return (-1);
}
