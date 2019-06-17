#include "header.h"

unsigned int clearPlace(unsigned int parkingRow, int pos) {
	return (parkingRow & ~(1 << pos));
}
