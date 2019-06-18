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
	if (powOf2(parkingRow))
		return (log2(parkingRow));
	return (-1);
}
