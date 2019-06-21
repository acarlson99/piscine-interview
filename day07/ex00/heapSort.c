#include "header.h"

void swap(struct s_art **a, struct s_art **b) {
	struct s_art *tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(struct s_art **arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left]->price > arr[largest]->price)
		largest = left;
	if (right < n && arr[right]->price > arr[largest]->price)
		largest = right;

	if (i != largest) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(struct s_art **masterpiece, int n) {
	for (int i = n / 2 - 1; i >= 0; --i)
		heapify(masterpiece, n, i);

	for (int i = n - 1; i >= 0; --i) {
		swap(&masterpiece[0], &masterpiece[i]);
		heapify(masterpiece, i, 0);
	}
}
