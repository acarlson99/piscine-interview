#include <stdlib.h>
#include "header.h"

void runSim(int dist, int *arr, int n, int placedIdx, int *cnt, int *totalPossible) {
	for (int i = 0; i < n; ++i) {
		if (i != placedIdx) {
			if (placedIdx < 0)
				runSim(dist, arr, n, i, cnt, totalPossible);
			else {
				++*totalPossible;
				if (abs(arr[placedIdx] - arr[i]) > dist)
					++*cnt;
			}
		}
	}
}

double probaDistance(int dist, int *arr, int n) {
	int cnt = 0;
	int totalPossible = 0;

	runSim(dist, arr, n, -1, &cnt, &totalPossible);

	return ((double)cnt / (double)totalPossible);
}
