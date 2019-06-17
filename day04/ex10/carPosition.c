#include "header.h"

int inc(int n) {
	if (n & 1)
		return (inc(n >> 1) << 1);
	return (n | 1);
}

int carPosition(unsigned parkingRow) {
	
}
