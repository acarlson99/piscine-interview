#include "header.h"

void rec(int n, struct s_array *array) {
	// for i from 0 to n
	// append to array
	// recurse if necessary
	// print boi if n - i == 0
}

void printPossibleSlices(int pizzaSize) {
	struct s_array *array = arrayInit();
	rec(pizzaSize, array);
}
