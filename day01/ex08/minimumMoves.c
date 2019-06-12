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

struct s_item {
	size_t         key; //here the key will be the address
	struct s_node  *node;
	struct s_item  *next;
};

struct s_dict {
	struct s_item **items;
	int           capacity; //the capacity of the array 'items'
};

struct s_dict *dictInit(int capacity) {
	struct s_dict *dict;
	struct s_item **items;

	if (!(dict = malloc(sizeof(struct s_dict))))
		return (NULL);
	if (!(items = malloc(sizeof(struct s_item*) * capacity))) {
		free(dict);
		return (NULL);
	}
	bzero(items, sizeof(struct s_items*) * capacity);
	dict->items = items;
	dict->capacity = capacity;
	return (dict);
}

int dictInsert(struct s_dict *dict, size_t key, struct s_node *node) {
	if (!dict || !node)
		return (0);
	size_t idx = key % dict->capacity;
	struct s_item *item;
	if (!(item = malloc(sizeof(struct s_item))))
		return (0);
	item->key = key;
	item->node = node;
	item->next = dict->items[idx];
	dict->items[idx] = item;
	return (1);
}

struct s_node *dictSearch(struct s_dict *dict, size_t key) {
	if (!dict)
		return (NULL);
	size_t idx = key % dict->capacity;
	for (struct s_item *i = dict->items[idx]; i; i = i->next) {
		if (key == i->key)
			return (i->node);
	}
	return (NULL);
}

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
	struct s_dict *dict = dictInit(10000);

	enqueue(q, &(struct s_info){begin, 0});
	dictInsert(dict, (size_t)begin, begin);
	while (!isEmpty(q)) {
		struct s_info *info = dequeue(q);
		int n = info->n;
		if (info->node->isFinal) {
			free(info);
			return (n);
		}
		if (info->node->next && !dictSearch(dict, (size_t)info->node->next))
			enqueue(q, &(struct s_info){info->node->next, n + 1});
		if (info->node->random && !dictSearch(dict, (size_t)info->node->next))
			enqueue(q, &(struct s_info){info->node->random, n + 1});
	}
	return (-1);
}
