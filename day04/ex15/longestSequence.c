#include "header.h"

int inc(int n) {
	if (n & 1)
		return (inc(n >> 1) << 1);
	return (n | 1);
}

int rec(unsigned bits, int acc) {
	if (bits)
		return (rec(bits & (bits << 1), inc(acc)));
	return (acc);
}

int longestSequence(unsigned parkingRow) {
	return (rec(parkingRow, 0));
}
