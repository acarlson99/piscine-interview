#include <math.h>
#include "header.h"

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
	double r = log2(parkingRow);
	if (modf(r, &r))
		return (~0);
	return ((int)r);
}
