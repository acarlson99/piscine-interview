#include "header.h"

unsigned setPlace(unsigned parkingRow, int pos) {
	return (parkingRow | (1 << pos));
}
