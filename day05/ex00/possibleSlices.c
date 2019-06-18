#include <stdio.h>
#include "header.h"

void rec(int target, struct s_array *array, int total) {
	if (total == target) {
		arrayPrint(array);
		return ;
	}
	else if (total > target)
		return ;
	for (int i = 0; i < target; ++i) {
		if (target - i <= 0)
			break ;
		arrayAppend(array, target - i);
		rec(target, array, total + (target - i));
		--array->length;
	}
}

void printPossibleSlices(int pizzaSize) {
	struct s_array *array = arrayInit();
	rec(pizzaSize, array, 0);
}
