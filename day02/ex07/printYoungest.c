#include <limits.h>
#include <stdio.h>
#include "header.h"

int min(int a, int b) {
	return (a < b ? a : b);
}

int findYoungest(int *ages, int left, int right) {
	int pi = (right + left) / 2;
	if (left == right)
		return (ages[left]);
	else if (left + 1 == right)
		return (min(ages[left], ages[left+1]));
	else
		return (min(findYoungest(ages, left, pi), findYoungest(ages, pi+1, right)));
}

void printYoungest(int *ages, int length) {
	printf("Youngest : %d\n", findYoungest(ages, 0, length-1));
}
