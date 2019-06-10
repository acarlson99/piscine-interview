#include "header.h"
#include <string.h>
#include <stdlib.h>

int partition(struct s_art **arts, int l, int h) {
	struct s_art *pivot = arts[h];
	int i = l - 1;

	for (int j = l; j < h; ++j) {
		if (strcmp(arts[j]->name, pivot->name) <= 0) {
			++i;
			struct s_art *tmp = arts[i];
			arts[i] = arts[j];
			arts[j] = tmp;
		}
	}
	struct s_art *tmp = arts[i+1];
	arts[i+1] = arts[h];
	arts[h] = tmp;
	return (i + 1);
}

void quickSort(struct s_art **arts, int l, int h) {
	if (l < h) {
		// partitioning index; arr[pi] is at the right place
		int pi = partition(arts, l, h);
		quickSort(arts, l, pi - 1);
		quickSort(arts, pi + 1, h);
	}
}

void sortArts(struct s_art **arts) {
	size_t i;
	for (i = 0; arts[i]; ++i);
	quickSort(arts, 0, i-1);
}
