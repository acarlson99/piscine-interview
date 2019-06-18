#include <stdio.h>
#include "header.h"

void aloneCans(int *arr, int n) {
	int boi = 0;
	for (int i = 0; i < n; ++i)
		boi ^= arr[i];
	// boi = a^b
	int x = boi ^ ~(boi-1);

	printf("%d\n%d\n", x, boi);
}
