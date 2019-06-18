#include <stdlib.h>
#include "header.h"

void fillBoi(int *arr, int n, int len) {
	if (len < 0)
		return ;
	if (n & 1)
		*arr = 1;
	else if (!n)
		return ;
	fillBoi(arr + 1, n / 2, len - 1);
}

int **pianoDecompress(struct s_bit *bit, int l) {
	int **arr = calloc(bit->n + 1, sizeof(int*));

	for (int i = 0; i < bit->n; ++i) {
		arr[i] = calloc(l, sizeof(int));
		fillBoi(arr[i], bit->arr[i], l);
	}
	return (arr);
}
