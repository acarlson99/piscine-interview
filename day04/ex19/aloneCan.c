#include <stdio.h>
#include "header.h"

void aloneCan(int *arr, int n) {
	int bruh = 0;

	for (int i = 0; i < n; ++i)
		bruh ^= arr[i];

	printf("%d\n", bruh);
}
