#include <string.h>
#include <stdlib.h>
#include "header.h"

struct s_node *makeList(char *contents) {
	struct s_node *head = malloc(sizeof(struct s_node));
	head->c = *contents++;
	head->prev = NULL;
	head->next = NULL;
	struct s_node *ptr = head;
	while (*contents) {
		ptr->next = malloc(sizeof(struct s_node));
		ptr->next->prev = ptr;
		ptr = ptr->next;
		ptr->c = *contents++;
	}
	head->prev = ptr;
	head->prev->next = head;
	return (head);
}

struct s_node *rotate(struct s_node *head, int n, size_t len) {
	if (n < 0)
		return (rotate(head, n + len, len));
	n %= len;
	while (n--)
		head = head->next;
	return (head);
}

char *precious(int *text, int size) {
	static struct s_node *head = NULL;
	if (!head)
		head = makeList(CS);
	static size_t len = strlen(CS);
	char *ret = malloc((size + 1) * sizeof(char));
	struct s_node *ptr = head;
	for (int i = 0; i < size; ++i) {
		ptr = rotate(ptr, text[i], len);
		ret[i] = ptr->c;
	}
	return (ret);
}
