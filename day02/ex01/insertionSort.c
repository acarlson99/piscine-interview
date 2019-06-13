#include <stdlib.h>
#include "header.h"

void insertionSort(struct s_player **players) {
	if (!players || !*players)
		return ;
	struct s_player *tmp = NULL;
	for (unsigned i = 1; players[i]; ++i) {
		if (i < 1)
			i = 1;
		if (players[i]->score < players[i-1]->score) {
			tmp = players[i];
			players[i] = players[i-1];
			players[i-1] = tmp;
			i -= 2;
		}
	}
}
