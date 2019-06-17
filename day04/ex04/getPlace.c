#include "header.h"

int getPlace(unsigned int parkingRow, int pos) {
	return ((parkingRow >> pos) & 1);
}
