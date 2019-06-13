#include "header.h"

int partition(struct s_player **players, int l, int h) {
	struct s_player *pivot = players[h];
	int i = l - 1;

	for (int j = l; j < h; ++j) {
		if (players[j]->score <= pivot->score) {
			++i;
			struct s_player *tmp = players[i];
			players[i] = players[j];
			players[j] = tmp;
		}
	}
	struct s_player *tmp = players[i+1];
	players[i+1] = players[h];
	players[h] = tmp;
	return (i + 1);
}

void qsort(struct s_player **players, int l, int h) {
	if (l < h) {
		int pi = partition(players, l, h);
		qsort(players, l, pi - 1);
		qsort(players, pi + 1, h);
	}
}

void quickSort(struct s_player **players) {
	unsigned i = 0;
	for (; players[i]; ++i);
	qsort(players, 0, i-1);
}
