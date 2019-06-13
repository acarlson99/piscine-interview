#include <math.h>
#include <stdlib.h>
#include "header.h"


struct s_stone *merge(struct s_stone *left, struct s_stone *right) {
	struct s_stone *ret = NULL;

	if (!right)
		return (left);
	else if (!left)
		return (right);
	if (left->size <= right->size) {
		ret = left;
		left = left->next;
		ret->next = NULL;
	}
	else {
		ret = right;
		right = right->next;
		ret->next = NULL;
	}
	struct s_stone *ptr = ret;
	while (left && right) {
		if (left->size <= right->size) {
			ptr->next = left;
			left = left->next;
		}
		else {
			ptr->next = right;
			right = right->next;
		}
		ptr = ptr->next;
	}
	if (left)
		ptr->next = left;
	else
		ptr->next = right;
	return (ret);
}

struct s_stone *sortList(struct s_stone *head, unsigned len) {
	struct s_stone *node;
	struct s_stone *left = NULL;
	struct s_stone *right = NULL;
	unsigned i = 0;

	if (len <= 1)
		return (head);
	node = head;
	for (i = 0; i < len; ++i) {
		struct s_stone *tmp = node;
		node = node->next;
		if (i < (len / 2)) {
			tmp->next = left;
			left = tmp;
		}
		else {
			tmp->next = right;
			right = tmp;
		}
	}
	left = sortList(left, len / 2);
	if (len % 2)
		right = sortList(right, len / 2 + 1);
	else
		right = sortList(right, len / 2);
	return (merge(left, right));
}

void sortStones(struct s_stone **stone) {
	unsigned len = 0;
	for (struct s_stone *node = *stone; node; node = node->next)
		++len;
	*stone = sortList(*stone, len);
}
