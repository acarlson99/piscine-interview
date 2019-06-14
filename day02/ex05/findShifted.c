#include "header.h"

int binarySearch(int *rocks, int value, int left, int right) {
	if (right < left)
		return (-1);
	int pi = (left + right) / 2;
	if (rocks[pi] > value)
		return (binarySearch(rocks, value, left, pi-1));
	else if (rocks[pi] < value)
		return (binarySearch(rocks, value, pi+1, right));
	else if (rocks[pi] == value)
		return (pi);
	else
		return (-1);
}

int searchShifted(int *rocks, int length, int value) {
	int pi = 0;
	for (; pi < length && rocks[pi] <= 1[rocks+pi]; ++pi) {
		if (rocks[pi] == value)
			return (pi);
	}
	return (binarySearch(rocks, value, pi, length));
}
