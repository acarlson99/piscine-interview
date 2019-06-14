#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"

int getDescription(struct s_info *info) {
	return (info->gender * pow(10,6)
			+ info->height * pow(10,5)
			+ info->hairColor * pow(10,4)
			+ info->eyeColor * pow(10,3)
			+ info->glasses * pow(10,2)
			+ info->tattoo * pow(10,1)
			+ info->piercing * pow(10,0));
}

void countSort(struct s_criminal **criminals, int exp) {
	int count[10] = { 0 };

	int len = 0;
	int i;
	for (len = 0; criminals[len]; ++len)
		++count[(criminals[len]->description / exp) % 10];

	for (i = 1; i < 10; ++i)
		count[i] += count[i-1];

	struct s_criminal **output = calloc(sizeof(*criminals), len);

	// for (i = 0; criminals[i]; ++i) {
	for (i = len - 1; i >= 0; --i) {
		output[count[(criminals[i]->description / exp) % 10] - 1] = criminals[i];
		--count[(criminals[i]->description / exp) % 10];
	}

	for (i = 0; criminals[i]; ++i)
		criminals[i] = output[i];
	free(output);
}

void sortCriminals(struct s_criminal **criminals) {
	int m = 0;
	for (int i = 0; criminals[i]; ++i)
		m = criminals[i]->description > m ? criminals[i]->description : m;
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(criminals, exp);
}

int binarySearch(struct s_criminal **criminals, int value, int left, int right) {
	if (right < left)
		return (-1);
	int pi = (left + right) / 2;
	if (!criminals[pi])
		return (-1);
	if (criminals[pi]->description > value)
		return (binarySearch(criminals, value, left, pi-1));
	else if (criminals[pi]->description < value)
		return (binarySearch(criminals, value, pi+1, right));
	else if (criminals[pi]->description == value)
		return (pi);
	else
		return (-1);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info) {
	int desc = getDescription(info);
	int i = 0;
	while (criminals[i])
		++i;
	int idx = binarySearch(criminals, desc, 0, i);
	int start = idx;
	if (idx < 0)
		return (NULL);
	while (start > 0 && criminals[start]->description == desc)
		--start;
	++start;
	int end = idx;
	while (criminals[end] && criminals[end]->description == desc)
		++end;
	struct s_criminal **lads = malloc(sizeof(struct s_criminal *) * (end - start + 1));
	for (i = 0; i + start < end; ++i)
		lads[i] = criminals[i + start];
	lads[i] = NULL;
	return (lads);
}
