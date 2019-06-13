#include "header.h"

int binarySearch(int *rocks, int length, int value, int left, int right) {
	int i = length / 2;
	if (length == 0 || !rocks[i])
		return (-1);
	int cmp = rocks[i] - value;
	if (!cmp)
		return (rocks[i]);
	else if (cmp > 0)
		return (binarySearch(rocks, i, value, i, right));
	else {
		if (i == 0)
			return (-1);
		return (binarySearch(rocks + i, length - i, value, i, right));
	}
}

int searchShifted(int *rocks, int length, int value) {
	int pi = 0;
	for (; pi < length && rocks[pi] >= 1[rocks+pi]; ++pi) {
		if (rocks[pi] == value)
			return (pi);
	}
	return (binarySearch(rocks, length - pi, value, pi, length));
}
