#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 10);
	printf("%d\n", tank->stacks[tank->n]->sum);
	tankPush(tank, 50);
	printf("%d\n", tank->stacks[tank->n]->sum);
	printf("%d\n", tankPop(tank));
	printf("%d\n", tank->stacks[tank->n]->sum);
	// tankPush(tank, 1000);
	printf("%d\n", tank->stacks[tank->n]->sum);
	printf("%d\n", tankPop(tank));
	printf("%d\n", tankPop(tank));
	printf("%d\n", tankPop(tank));

	for (int i = 0; i < 9; ++i)
		tankPush(tank, 100);
	tankPush(tank, 99);
	// tankPush(tank, 110);
	printf("%d\n", tank->stacks[tank->n]->sum);
	tankPush(tank, 100);
	printf("%d\n", tank->stacks[tank->n]->sum);
	tankPush(tank, 10);
	printf("%d\n", tank->stacks[tank->n]->sum);
	printf("%d\n", tankPop(tank));
	printf("%d\n", tank->stacks[tank->n]->sum);
	printf("%d\n", tankPop(tank));
	printf("%d\n", tank->stacks[tank->n]->sum);
	printf("%d\n", tankPop(tank));
	printf("%d\n", tank->stacks[tank->n]->sum);
	return (0);
}



// Function used for the test
// Don't go further :)
