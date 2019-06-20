#include "header.h"

int selectHotspots(struct s_hotspot **hotspots) {
	int ret;
	int maxrange;

	if (!hotspots)
		return (0);
	ret = 1;
	maxrange = 0;
	for (int i = 1; hotspots[i]; i++) {
		if (hotspots[i]->pos - hotspots[i]->radius >= maxrange) {
			maxrange = hotspots[i]->pos + hotspots[i]->radius;
			ret++;
		}
	}
	return (ret);
}
