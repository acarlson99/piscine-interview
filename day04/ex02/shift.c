#include <stdlib.h>
#include "header.h"

int max(int a, int b) {
	return (a > b ? a : b);
}

int min(int a, int b) {
	return (a < b ? a : b);
}

char *rightShift(char *bin, int k) {
	// memmove(bin + k, bin, 6 - k);
	char msb = *bin;
	for (int i = 6 - k; i >= 0; --i) {
		if (i + k < 6)
			bin[i+k] = bin[i];
	}
	for (int i = min(k - 1, 5); i >= 0; --i)
		bin[i] = msb;
	return (bin);
}

char *leftShift(char *bin, int k) {
	// memmove(bin, bin + k, 6 - k);
	for (int i = 0; i < max(6 - k, 6); ++i) {
		if (i + k < 6)
			bin[i] = bin[i+k];
	}
	for (int i = max(6 - k, 0); i < 6; ++i)
		bin[i] = '0';
	return (bin);
}

int toInt(char *bits) {
	int n = strtol(bits, NULL, 2);
	if (n < 31)
		return (n);
	return (-(64 - n));
}
