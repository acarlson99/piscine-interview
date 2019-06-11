#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct s_string *stringInit(void) {
	struct s_string	*s = malloc(sizeof(struct s_string));
	s->capacity = 600000000;
	s->content = malloc(s->capacity * sizeof(char));
	s->length = 0;
	return (s);
}

int stringAppend(struct s_string *dyString, char *str) {
	if (!str)
		return (0);
	size_t len = strlen(str);
	if ((size_t)(dyString->length + dyString->capacity) <= len) {
		dyString->capacity *= 2;
		if (!(dyString->content = realloc(dyString->content, dyString->capacity)))
			return (0);
		return (stringAppend(dyString, str));
	}
	if (!memmove(dyString->content + dyString->length, str, len))
		return (0);
	dyString->length += len;
	dyString->content[dyString->length] = '\0';
	return (1);
}

char *decompress(char *cBook) {
	struct s_string *s = stringInit();

	size_t end = strcspn(cBook, ">");
	char *thing1 = strndup(cBook, end);
	char *thing2 = thing1 + 1;
	char **dict = malloc(100 * sizeof(char*));
	char *token;
	int dictlen = 0;
	while ((token = strsep(&thing2, ",")))
		dict[dictlen++] = token;

	cBook += end + 1;
	size_t a = 0;
	for (size_t i = 0; cBook[i]; cBook[i] == '@' ? ++a : 0 , ++i);
	char **splitBoi = malloc((a + 1) * sizeof(char*));
	size_t splitLen = 0;
	while (splitLen < a && (token = strsep(&cBook, "@")))
		splitBoi[splitLen++] = token;

	stringAppend(s, splitBoi[0]);
	for (int i = 1; splitBoi[i]; ++i) {
		if (splitBoi[i][0] > dictlen) {
			stringAppend(s, "@");
			stringAppend(s, splitBoi[i]);
		}
		else {
			stringAppend(s, dict[(int)splitBoi[i][0]-1]);
			stringAppend(s, splitBoi[i] + 1);
		}
	}
	char *ret = s->content;
	free(splitBoi);
	free(dict);
	free(s);
	free(thing1);
	return (ret);
}
