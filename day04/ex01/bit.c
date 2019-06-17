#include <stdlib.h>
#include "header.h"

#define GETNOT(c, notc) ((c) + (notc) > '1' ? '0' : (c) + (notc))

char *getAnd(char *a, char *b) {
	int nota = 0;
	int notb = 0;
	int lena = 0;
	int lenb = 0;

	for (; lena[a] == '~'; ++a)
		nota ^= 1;
	for (; lenb[b] == '~'; ++b)
		notb ^= 1;

	int idx = 0;
	for (int i = 0; i < 4; ++i) {
		a[idx] = GETNOT(a[i+lena], nota) == GETNOT(b[i+lenb], notb) ? GETNOT(a[i+lena], nota) : '0';
		++idx;
	}
	a[idx] = '\0';
	return (a);
}

char *getOr(char *a, char *b) {
	int nota = 0;
	int notb = 0;
	int lena = 0;
	int lenb = 0;

	for (; lena[a] == '~'; ++a)
		nota ^= 1;
	for (; lenb[b] == '~'; ++b)
		notb ^= 1;

	int idx = 0;
	for (int i = 0; i < 4; ++i) {
		a[idx] = (GETNOT(a[i+lena], nota) == '1' || GETNOT(b[i+lenb], notb) == '1') + '0';
		++idx;
	}
	a[idx] = '\0';
	return (a);
}

int toInt(char *bits) {
	return (strtol(bits, NULL, 2));
}
