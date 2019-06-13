#include <stdlib.h>
#include "header.h"

void merge(struct s_player **arr, int left_i, int m, int right_i) {
	int n1 = m - left_i + 1;
	int n2 = right_i - m;
	int i = 0;
	int j = 0;
	struct s_player **left = malloc((n1) * sizeof(struct s_player *));
	struct s_player **right = malloc((n2) * sizeof(struct s_player *));

	for (i = 0; i < n1; ++i)
		left[i] = arr[i+left_i];
	for (j = 0; j < n2; ++j)
		right[j] = arr[j+m+1];

	i = 0;
	j = 0;
	int k = left_i;
	while (i < n1 && j < n2) {
		if (left[i]->score > right[j]->score)
			arr[k] = left[i++];
		else
			arr[k] = right[j++];
		++k;
	}
	while (i < n1)
		arr[k++] = left[i++];
	while (j < n2)
		arr[k++] = right[j++];

	free(right);
	free(left);
}

void f(struct s_player **arr, int left_i, int right_i) {
	if (left_i < right_i) {
		int m = left_i + (right_i - left_i) / 2;
		f(arr, left_i, m);
		f(arr, m + 1, right_i);
		merge(arr, left_i, m, right_i);
	}
}

struct s_player **mergeSort(struct s_player **players) {
	if (!players)
		return players;
	int i = 0;
	for (; players[i]; ++i);
	f(players, 0, i-1);
	return (players);
}
