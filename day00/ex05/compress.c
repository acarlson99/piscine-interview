#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

#define FVN_OFFSET_BASIS 0xcbf29ce484222325
#define FVN_PRIME 0x100000001b3

size_t hash(char *input) {
	size_t hash = FVN_OFFSET_BASIS;
	for (size_t i = 0; input[i]; ++i) {
		hash = hash * FVN_PRIME;
		hash = hash ^ input[i];
	}
	return (hash);
}

size_t hash_(char *input, size_t len) {
	size_t hash = FVN_OFFSET_BASIS;
	for (size_t i = 0; i < len && input[i]; ++i) {
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

int dictInsert(struct s_dict *dict, char *key, int value) {
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

int dictSearch(struct s_dict *dict, char *key) {
	if (!dict || !key)
		return (-1);
	size_t idx = hash(key) % dict->capacity;
	for (struct s_item *i = dict->items[idx]; i; i = i->next) {
		if (!strcmp(key, i->key))
			return (i->value);
	}
	return (-1);
}

int searchWord(struct s_dict *dict, char *ptr) {
	size_t len = strcspn(ptr, " \n\t\v\r\f");
	char tmp = ptr[len];
	ptr[len] = '\0';
	int r = dictSearch(dict, ptr);
	ptr[len] = tmp;
	return (r);
}

struct s_item *getItem(struct s_dict *dict, int n) {
	for (int i = 0; i < dict->capacity; ++i) {
		for (struct s_item *item = dict->items[i]; item; item = item->next) {
			if (item->value == n)
				return (item);
		}
	}
	return (NULL);
}

char *makeHeader(struct s_dict *dict) {
	size_t total = 2;
	for (int i = 0; i < dict->capacity; ++i) {
		struct s_item *it = dict->items[i];
		for (struct s_item *item = it; item; item = item->next)
			total += strlen(it->key) + 1;
	}
	char *ret = malloc(total * sizeof(char));
	int num;
	int done = 0;
	char *ptr = ret + sprintf(ret, "<");
	for (num = 0; !done; ++num) {
		done = 1;
		struct s_item *item = getItem(dict, num);
		if (!item)
			break ;
		ptr += sprintf(ptr, "%s%s", num == 0 ? "" : ",", item->key);
	}
	ptr += sprintf(ptr, ">%c", '\0');
	return (ret);
}

char *compress(char *book, struct s_dict *dict) {
	size_t n = strlen(book);
	char *header = makeHeader(dict);
	size_t headlen = strlen(header);
	printf("%s\n", header);
	char *ret = realloc(header, ((strlen(header) + n + 1) * sizeof(char)));
	// char *ret = malloc((n + 1) * sizeof(char));
	char *ptr = ret + headlen;
	for (size_t i = 0; i < n;) {
		while (isspace(book[i]))
			++i;
		int idx = searchWord(dict, book + i);
		if (idx < 0) {
			while (book[i] && !isspace(book[i])) {
				*ptr++ = book[i++];
			}
		}
		else {
			*ptr++ = '@';
			*ptr++ = idx;
			while (book[i] && !isspace(book[i]))
				++i;
		}
		while (isspace(book[i])) {
			*ptr++ = book[i++];
		}
	}
	*ptr = '\0';
	return (ret);
}
