#include <string.h>
#include "header.h"

int searchPrice(struct s_art **arts, char *name) {
	for (; *arts; ++arts) {
		if ((*arts)->name && !strcmp((*arts)->name, name))
			return ((*arts)->price);
	}
	return (-1);
}
