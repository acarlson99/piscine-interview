#include "header.h"

int inc(int n) {
	if (n & 1)
		return (inc(n >> 1) << 1);
	return (n | 1);
}

int rec(unsigned parkingRow) {
	if (parkingRow >> 1)
		return (inc(rec(parkingRow >> 1)));
	return (0);
}

int powOf2(unsigned bits) {
	if (bits) {
		if (bits >> 1) {
			if (bits & 1)
				return (0);
			return (powOf2(bits >> 1));
		}
		return (1);
	}
	return (0);
}

int carPosition(unsigned parkingRow) {
	if (powOf2(parkingRow))
		return (rec(parkingRow));
	return (-1);
}
