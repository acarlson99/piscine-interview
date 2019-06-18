#include <stdio.h>
#include "header.h"

void aloneCans(int *arr, int n) {
	int boi = 0;
	for (int i = 0; i < n; ++i)
		boi ^= arr[i];
	int mask = boi & ~(boi-1);
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] & mask)
			a ^= arr[i];
		else
			b ^= arr[i];
	}

	printf("%d\n%d\n", a, b);
}
