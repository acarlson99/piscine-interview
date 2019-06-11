#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct s_stack *stackInit(void) {
	struct s_stack		*new;

	if (!(new = (struct s_stack *)malloc(sizeof(struct s_stack))))
		return (NULL);
	new->item = NULL;
	return (new);
}

void *pop(struct s_stack *stack) {
	struct s_item *tmp;
	void *tptr;

	if (!stack || !stack->item)
		return (NULL);
	tmp = stack->item;
	stack->item = stack->item->next;
	tptr = tmp->word;
	free(tmp);
	return (tptr);
}

void push(struct s_stack *stack, char *word) {
	struct s_item *new;

	if (!stack)
		return ;
	if (!(new = (struct s_item *)malloc(sizeof(struct s_item))))
		return ;
	new->word = word;
	new->next = stack->item;
	stack->item = new;
}

void printReverseV2(struct s_node *lst) {
	struct s_stack *s = stackInit();
	int i = 0;

	for (; lst; lst = lst->next)
		push(s, lst->word);
	for (char *word = pop(s); word; word = pop(s)) {
		if (i)
			printf(" ");
		i = 1;
		printf("%s", word);
	}
	printf("\n");
}
