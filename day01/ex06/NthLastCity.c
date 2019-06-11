#include <stdio.h>
#include <stdlib.h>
#include "header.h"

char *f(struct s_city *city, int n, int *n_) {
	if (!city)
		return (NULL);
	char *r = f(city->next, n, n_);
	if (r)
		return (r);
	if (*n_ == n)
		return (city->name);
	++*n_;
	return (NULL);
}

char *NthLastCity(struct s_city *city, int n) {
	int n_ = 0;
	return (f(city, n, &n_));
}
