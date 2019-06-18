#include "header.h"

int inc(int n) {
	if (n & 1)
		return (inc(n >> 1) << 1);
	return (n | 1);
}

int rec(unsigned bits) {
	if (bits & 1)
		return (0);
	return (inc(rec(bits >> 1)));
}

int rightmostCar(unsigned parkingRow) {
	if (parkingRow)
		return (rec(parkingRow));
	return (~0);
}
