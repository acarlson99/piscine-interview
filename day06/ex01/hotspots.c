#include "header.h"

int selectHotspots(struct s_hotspot **hotspots) {
	int ret = 1;
	int pos = hotspots[0]->pos;
	int area = hotspots[0]->radius;

	for (int i = 1; hotspots[i]; ++i) {
		if (pos + area <= hotspots[i]->pos - hotspots[i]->radius) {
			++ret;
			pos = hotspots[i]->pos;
			area = hotspots[i]->radius;
		}
	}
	return (ret);
}
