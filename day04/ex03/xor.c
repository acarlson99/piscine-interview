#include <stdlib.h>
#include "header.h"

char *getXor(char *a, char *b) {
	for (int i = 0; i < 6; ++i) {
		a[i] = (a[i] != b[i]) + '0';
	}
	return (a);
}

int toInt(char *bits) {
	return (strtol(bits, NULL, 2));
}
