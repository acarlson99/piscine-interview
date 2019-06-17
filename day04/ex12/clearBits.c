#include "header.h"

unsigned clearBits(unsigned parkingRow, int n) {
	return ((~0 << n) & parkingRow);
}
