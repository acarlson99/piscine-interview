#include <string.h>
#include <stdlib.h>
#include "header.h"

int isEmpty(struct s_queue *queue) {
	return (!queue->first);
}

struct s_node *findMe(struct s_graph *graph, char *youAreHere) {
	struct s_queue *q = queueInit();
	int i = 0;
	struct s_node *node;

	for (; graph->places[i]; ++i)
		enqueue(q, graph->places[i]);
	while (!isEmpty(q)) {
		node = dequeue(q);
		if (node->visited) {
			node = NULL;
			continue ;
		}
		node->visited = 1;
		if (!strcmp(youAreHere, node->name))
			break ;
		for (i = 0; node->connectedPlaces[i]; ++i)
			enqueue(q, node->connectedPlaces[i]);
		node = NULL;
	}
	while (!isEmpty(q))
		dequeue(q);
	free(q);
	return (node);
}

void findSellers(struct s_sellers *sellers, struct s_queue *q, int distance) {
	struct s_node *node;
	int foundCereal = 0;
	struct s_queue *nextQueue = queueInit();
	int sidx = 0;
	int i = 0;

	while (!isEmpty(q)) {
		node = dequeue(q);
		if (!node)
			break ;
		if (node->visited == 2)
			continue ;
		node->visited = 2;
		if (node->hasCerealBar) {
			sellers->placeNames[sidx++] = node->name;
			foundCereal = 1;
		}
		for (i = 0; !foundCereal && node->connectedPlaces[i]; ++i) {
			if (node->connectedPlaces[i]->visited != 2)
				enqueue(nextQueue, node->connectedPlaces[i]);
		}
	}
	if (!foundCereal)
		findSellers(sellers, nextQueue, distance + 1);
	else {
		sellers->placeNames[sidx] = NULL;
		sellers->distance = distance;
	}
	
}

struct s_sellers *closestSellers(struct s_graph *graph, char *youAreHere) {
	struct s_queue *q = queueInit();
	struct s_node *me = findMe(graph, youAreHere);
	int i = 0;

	if (!me)
		return (NULL);

	struct s_sellers *s = malloc(sizeof(struct s_sellers));
	s->distance = 0;
	s->placeNames = malloc(sizeof(char*) * 420);
	s->placeNames[0] = NULL;
	if (me->hasCerealBar) {
		s->placeNames[0] = me->name;
		s->distance = 0;
		return (s);
	}
	for (i = 0; me->connectedPlaces[i]; ++i)
		enqueue(q, me->connectedPlaces[i]);
	me->visited = 2;
	findSellers(s, q, 1);
	if (!*s->placeNames) {
		free(s->placeNames);
		free(s);
		return (NULL);
	}
	return (s);
}
