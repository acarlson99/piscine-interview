#include <stdio.h>
#include "header.h"

void rec(int target, int n, struct s_array *array, int total) {
	if (total == target) {
		arrayPrint(array);
		return ;
	}
	else if (total > target)
		return ;
	for (int i = 0; i < target; ++i) {
		if (n - i <= 0)
			break ;
		arrayAppend(array, n - i);
		rec(target, n - i, array, total + (n - i));
		--array->length;
	}
}

void printPossibleSlices(int pizzaSize) {
	struct s_array *array = arrayInit();
	rec(pizzaSize, pizzaSize, array, 0);
}
