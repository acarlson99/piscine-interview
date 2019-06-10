#include <string.h>
#include "header.h"

#define FVN_OFFSET_BASIS 0xcbf29ce484222325
#define FVN_PRIME 0x100000001b3

size_t hash(char *input) {
	size_t hash = FVN_OFFSET_BASIS;
	for (int i = 0; input[i]; ++i) {
		hash = hash * FVN_PRIME;
		hash = hash ^ input[i];
	}
	return (hash);
}

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

int dictInsert(struct s_dict *dict, char *key, struct s_art *value) {
	if (!dict || !value || !key)
		return (0);
	size_t idx = hash(key) % dict->capacity;
	struct s_item *item;
	if (!(item = malloc(sizeof(struct s_item))))
		return (0);
	item->key = strdup(key);
	item->value = value;
	item->next = dict->items[idx];
	dict->items[idx] = item;
	return (1);
}

struct s_art *dictSearch(struct s_dict *dict, char *key) {
	if (!dict || !key)
		return (NULL);
	size_t idx = hash(key) % dict->capacity;
	for (struct s_item *i = dict->items[idx]; i; i = i->next) {
		if (!strcmp(key, i->key))
			return (i->value);
	}
	return (NULL);
}

int searchPrice(struct s_dict *dict, char *name) {
	struct s_art *art = dictSearch(dict, name);
	if (art)
		return (art->price);
	return (-1);
}
