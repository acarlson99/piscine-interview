#include "header.h"
#include <stdlib.h>

void countSort(unsigned char *utensils, int n) {
	int count[256] = { 0 };

	for (int i = 0; i < n; ++i)
		++count[utensils[i]];

	for (int i = 1; i <= 255; ++i)
		count[i] += count[i-1];

	unsigned char *output = calloc(sizeof(*utensils), n);

	for (int i = 0; i < n; ++i) {
		--count[utensils[i]];
		output[count[utensils[i]]] = utensils[i];
	}

	for (int i = 0; i < n; ++i)
		utensils[i] = output[i];
	free(output);
}
