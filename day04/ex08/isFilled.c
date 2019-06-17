#include "header.h"

int isFilled(unsigned parkingRow) {
	if (parkingRow)
		return (parkingRow & 1 & isFilled(parkingRow >> 1));
	return (1);
}
