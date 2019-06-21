#include <math.h>
#include "header.h"

int carPosition(unsigned parkingRow) {
	double r = log2(parkingRow);
	if (modf(r, &r))
		return (~0);
	return ((int)r);
}
