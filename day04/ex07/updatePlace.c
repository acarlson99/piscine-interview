#include "header.h"

unsigned updatePlace(unsigned parkingRow, int pos, int value) {
	return ((parkingRow & ~(1 << pos)) | (value << pos));
}
