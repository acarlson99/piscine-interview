#include <stdlib.h>
#include "header.h"

struct s_string *stringInit(void) {
	struct s_string	*s = malloc(sizeof(struct s_string));
	s->capacity = 4;
	s->content = malloc(s->capacity * sizeof(char));
	s->length = 0;
}

int stringAppend(struct s_string *dyString, char *str) {

}

char *decompress(char *cBook) {

}
