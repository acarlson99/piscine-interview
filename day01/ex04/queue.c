#include <stdlib.h>
#include "header.h"

struct s_queue *queueinit(void) {
	struct s_queue *new;

	if (!(new = (struct s_queue *)malloc(sizeof(struct s_queue))))
		return (NULL);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, char *message) {
	struct s_node *ptr;
	struct s_node *new;

	if (!(queue && message))
		return ;
	if (!(new = (struct s_node *)malloc(sizeof(struct s_node))))
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

char *dequeue(struct s_queue *queue) {
	struct s_node *a;
	struct s_node *b;
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

char *peek(struct s_queue *queue) {
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
