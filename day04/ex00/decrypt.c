#include <stdlib.h>
#include "header.h"

char *getSum(char *a, char *b) {
	int overflow = 0;
	int n;

	for (int i = 5; i >= 0; --i) {
		n = (a[i] - '0') + (b[i] - '0') + overflow;
		overflow = n / 2;
		a[i] = n % 2 + '0';
	}
	return (a);
}

int toInt(char *a) {
	return (strtol(a, NULL, 2));
}
