#include "header.h"
#include <string.h>

int searchPrice(struct s_art **arts, int n, char *name) {
	int i = n / 2;
	if (n == 0 || !arts[i])
		return (-1);
	int cmp = strcmp(arts[i]->name, name);
	if (!cmp)
		return (arts[i]->price);
	else if (cmp > 0)
		return (searchPrice(arts, i, name));
	else {
		if (i == 0)
			return (-1);
		return (searchPrice(arts + i, n - i, name));
	}
}
