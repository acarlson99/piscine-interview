#include <math.h>
#include <string.h>
#include "header.h"

float getMax(struct s_graph *graph, struct s_node *sink) {
	float max = 0;

	if (sink->visited)
		return (0.);
	sink->visited = 1;
	for (int i = 0; sink->connectedPlaces[i]; ++i)
		max = fmax(getMax(graph, sink->connectedPlaces[i]), max);
	return (max + sink->population);
}

float maxTraffic(struct s_graph *parisPlaces, char *eventHere) {
	struct s_node *node = NULL;

	for (int i = 0; parisPlaces->places[i]; ++i) {
		if (!strcmp(eventHere, parisPlaces->places[i]->name)) {
			node = parisPlaces->places[i];
			break ;
		}
	}
	if (!node)
		return (-1.);
	return (getMax(parisPlaces, node));
}
