#include <stdlib.h>
#include <string.h>
#include "header.h"

#define FVN_OFFSET_BASIS 0xcbf29ce484222325
#define FVN_PRIME 0x100000001b3

size_t hash(char *input, size_t len) {
	size_t hash = FVN_OFFSET_BASIS;
	for (size_t i = 0; i < len && input[i]; ++i) {
		hash = hash * FVN_PRIME;
		hash = hash ^ input[i];
	}
	return (hash);
}

int howManyJesus(char *bible, char *jesus) {
	size_t m = strlen(jesus);
	size_t n = strlen(bible);
	size_t hpattern = hash(jesus, -1);
	int cnt = 0;
	for (size_t i = 0; i < n - m + 1; ++i) {
		size_t hs = hash(bible + i, m);
		if (hs == hpattern)
			++cnt;
	}
	return (cnt);
}
