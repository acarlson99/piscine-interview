#include <stdio.h>
#include "header.h"

void printReverse_(struct s_node *lst) {
	if (!lst)
		return ;
	if (!lst->next) {
		printf("%s", lst->word);
	}
	else {
		printReverse_(lst->next);
		printf(" %s", lst->word);
	}
}

void printReverse(struct s_node *lst) {
	printReverse_(lst);
	printf("\n");	// Example had newlines 🤷
}
