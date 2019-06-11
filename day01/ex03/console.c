#include <string.h>
#include <unistd.h>
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

int pop(struct s_stack *stack) {
	struct s_item *tmp;
	int tmp_;

	if (!stack || !stack->item)
		return (-1);
	tmp = stack->item;
	stack->item = stack->item->next;
	tmp_ = tmp->idx;
	return (tmp_);
}

void push(struct s_stack *stack, int idx) {
	struct s_item *new;

	if (!stack)
		return ;
	if (!(new = (struct s_item *)malloc(sizeof(struct s_item))))
		return ;
	new->idx = idx;
	new->next = stack->item;
	stack->item = new;
}

char *console(void) {
	struct s_stack *s = stackInit();
	char buf[255] = { 0 };
	char *msg = malloc((255 + 1) * sizeof(char));
	char nl = '\n';

	printf("> ");
	while (scanf("%[^\n]", buf) > 0) {
		if (!strcmp("UNDO", buf)) {
			int idx = pop(s);
			if (idx < 0)
				continue ;
			msg[idx] = '\0';
		}
		else if (!strcmp("SEND", buf)) {
			break ;
		}
		else {
			push(s, strlen(msg));
			strcat(msg, buf);
		}
		scanf("%c", &nl);
		printf("%s\n", msg);
		printf("> ");
	}
	return (msg);
}
