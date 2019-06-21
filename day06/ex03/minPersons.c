#include <math.h>
#include "header.h"

#define P(n) (1. - (pow((elements - 1.) / elements, (n * (n - 1.)) / 2.)))

int minPersons(int elements, int minPercentage) {
	for (int n = 0; ; ++n) {
		if (P(n) * 100 >= minPercentage)
			return (n);
	}
}
