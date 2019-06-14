#include <stdlib.h>
#include "header.h"

#define FVN_OFFSET_BASIS 0xcbf29ce484222325
#define FVN_PRIME 0x100000001b3

size_t hash(char *input) {
	size_t hash = FVN_OFFSET_BASIS;
	for (size_t i = 0; input[i]; ++i) {
		hash = hash * FVN_PRIME;
		hash = hash ^ input[i];
	}
	return (hash);
}

int getBois(struct s_node *root, size_t a, size_t b, struct s_node **r) {
	size_t h = hash(root->name);
	int cnt = 0;
	if (h == a)
		++cnt;
	if (h == b)
		++cnt;
	for (int i = 0; root->children[i]; ++i)
		cnt += getBois(root->children[i], a, b, r);
	if (cnt >= 2 && *r == NULL)
		*r = root;
	return (cnt);
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies) {
	struct s_node *r = NULL;
	getBois(root, hash(firstSpecies), hash(secondSpecies), &r);
	return (r);
}
