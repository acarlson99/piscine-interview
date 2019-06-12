#include <assert.h>
#include <stdlib.h>
#include "header.h"

#define CAPACITY 1000
#define NUMSTACKS 50

struct s_stack *newStack(void) {
	struct s_stack *s = NULL;
	if (!(s = malloc(sizeof(struct s_stack))))
		return (NULL);
	s->sum = 0;
	s->elem = NULL;
	return (s);
}

struct s_elem *newElem(int n) {
	struct s_elem *e = NULL;
	if (!(e = malloc(sizeof(struct s_elem))))
		return (NULL);
	e->energy = n;
	e->next = NULL;
	return (e);
}

struct s_tank *initTank(void) {
	struct s_tank *tank = malloc(sizeof(tank));
	if (!tank)
		return (NULL);
	tank->n = 0;
	tank->stacks = malloc(sizeof(struct s_stack*) * NUMSTACKS);
	if (!tank->stacks) {
		free(tank);
		return (NULL);
	}
	if (!(tank->stacks[0] = newStack())) {
		free(tank->stacks);
		free(tank);
		return (NULL);
	}
	return (tank);
}

void tankPush(struct s_tank *tank, int energy) {
	if (energy < 10 || energy > 100 || !tank || tank->n >= NUMSTACKS)
		assert(0); // return ;
	if (tank->stacks[tank->n]->sum + energy > CAPACITY) {
		tank->n++;
		if (tank->n >= NUMSTACKS)
			return ;
		tank->stacks[tank->n] = newStack();
	}
	struct s_elem *e = newElem(energy);
	e->next = tank->stacks[tank->n]->elem;
	tank->stacks[tank->n]->elem = e;
	tank->stacks[tank->n]->sum += e->energy;
}

int tankPop(struct s_tank *tank) {
	if (!tank || tank->n < 0)
		return (-1);
	struct s_stack *s = tank->stacks[tank->n];
	if (!s)
		return (-1);
	struct s_elem *e = s->elem;
	if (!e && tank->n > 0) {
		free(tank->stacks[tank->n]);
		tank->stacks[tank->n] = NULL;
		--tank->n;
		return (tankPop(tank));
	}
	else if (!e)
		return (-1);
	s->sum -= e->energy;
	tank->stacks[tank->n]->elem = e->next;
	e->next = NULL;
	int n = e->energy;
	free(e);
	return (n);
}
