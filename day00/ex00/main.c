#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "header.h"

size_t		numlines(char *buf, char c) {
	size_t i = 0;
	for (; *buf; ++buf)
		if (*buf == c)
			++i;
	return (i);
}

#define NEWLINE 0xa	// avoids magic numbers

struct s_art **parseArt(char *buf, int *num) {
	struct s_art **arts = malloc((numlines(buf, NEWLINE) + 1) * sizeof(struct s_art *));
	size_t i = 0;
	for (i = 0; *buf; ++i) {
		arts[i] = malloc(sizeof(struct s_art));
		while (*buf && *buf != NEWLINE)
			++buf;
	}
	arts[i] = NULL;
	*num = (int)i;
	return (arts);
}

int main() {
	FILE	*f = fopen("art.txt", "rb");

	fseek(f, 0, SEEK_END);
	long	size = ftell(f);
	int		numArts = 0;
	if (!f)
		return (1);
	rewind(f);
	char *buf = malloc(size + 1);
	fread(buf, sizeof(char), size, f);
	fclose(f);
	struct s_art **arts = parseArt(buf, &numArts);
}
