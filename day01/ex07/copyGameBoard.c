#include <string.h>
#include <stdlib.h>
#include "header.h"

struct s_item {
	int            key; //here the key will be the address
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

struct s_node *dictSearch(struct s_dict *dict, int key) {
	if (!dict)
		return (NULL);
	size_t idx = key % dict->capacity;
	for (struct s_item *i = dict->items[idx]; i; i = i->next) {
		if (key == i->key)
			return (i->node);
	}
	return (NULL);
}

struct s_node *newNode(int value) {
	struct s_node *node = malloc(sizeof(*node));
	node->value = value;
	node->random = NULL;
	node->next = NULL;
	return (node);
}

struct s_node *cloneNode(struct s_node *node, struct s_dict *dict) {
	struct s_node *search = NULL;
	if (!node)
		return (NULL);
	if (!(search = dictSearch(dict, node->value))) {
		struct s_node *head = newNode(node->value);
		dictInsert(dict, head->value, head);
		head->next = cloneNode(node->next, dict);
		head->random = cloneNode(node->random, dict);
		return (head);
	}
	else {
		return (search);
	}
}

void killDict(struct s_dict *dict) {
	for (int i = 0; i < dict->capacity; ++i) {
		for (struct s_item *item = dict->items[i]; item;) {
			struct s_item *tmp = item;
			item = item->next;
			free(tmp);
		}
	}
	free(dict->items);
	free(dict);
}

struct s_node *cloneGameBoard(struct s_node *node) {
	struct s_dict *dict = dictInit(1000);
	struct s_node *head = cloneNode(node, dict);
	killDict(dict);
	return (head);
}
