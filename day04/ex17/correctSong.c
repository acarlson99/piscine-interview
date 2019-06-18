#include "header.h"

void correctSong(struct s_bit *bit, int l, int row, int col, int dist) {
	if (!bit || !bit->arr || row >= l)
		return ;
	for (int i = 0; i < dist && row + i < bit->n; ++i)
		bit->arr[row + i] = 1 << col;
}
