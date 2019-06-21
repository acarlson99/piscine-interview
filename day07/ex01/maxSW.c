#include <stdlib.h>
#include <limits.h>
#include "header.h"

struct s_deque *dequeInit(void) {
	struct s_deque *dq = malloc(sizeof(struct s_deque));

	if (!dq)
		return (NULL);
	dq->first = NULL;
	dq->last = NULL;
	return (dq);
}

void pushFront(struct s_deque *deque, int value) {
	struct s_dequeNode *node = malloc(sizeof(struct s_dequeNode));

	if (!node)
		return ;
	node->value = value;
	node->prev = NULL;
	node->next = deque->first;
	if (node->next)
		node->next->prev = node;
	if (!deque->last)
		deque->last = node;
	deque->first = node;
}

void pushBack(struct s_deque *deque, int value) {
	struct s_dequeNode *node = malloc(sizeof(struct s_dequeNode));

	if (!node)
		return ;
	node->value = value;
	node->prev = deque->last;
	if (node->prev)
		node->prev->next = node;
	if (!deque->first)
		deque->first = node;
	node->next = NULL;
	deque->last = node;
}

int popFront(struct s_deque *deque) {
	struct s_dequeNode *node = deque->first;

	if (!node)
		return (INT_MIN);
	deque->first = node->next;
	if (!deque->first)
		deque->last = NULL;
	else
		node->next->prev = NULL;
	int ret = node->value;
	free(node);
	return (ret);
}

int popBack(struct s_deque *deque) {
	struct s_dequeNode *node = deque->last;

	if (!node)
		return (INT_MIN);
	deque->last = node->prev;
	if (!deque->last)
		deque->first = NULL;
	else
		node->prev->next = NULL;
	int ret = node->value;
	free(node);
	return (ret);
}

int max__(int a, int b) {
	return (a > b ? a : b);
}

struct s_max *maxSlidingWindow(int *arr, int n, int k) {
	struct s_deque *dq;
	struct s_max *info = malloc(sizeof(struct s_max));

	info->max = malloc(sizeof(int) * (n - k + 1));
	info->length = 0;
	dq = dequeInit();
	int i = 0;
	int max = INT_MIN;
	for (; i < k; ++i) {
		max = max__(arr[i], max);
		pushFront(dq, arr[i]);
	}
	info->max[info->length++] = max;
	printf("%d\n", *info->max);
	return (NULL);
}
