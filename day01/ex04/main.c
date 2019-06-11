#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	char a[] = "Apples"; (void)a;
	char b[] = "Banananananas"; (void)b;
	char c[] = "Charlemagne"; (void)c;
	char d[] = "dddddddicks"; (void)d;

	struct s_queue *queue = NULL;
	printf("%s\n", peek(queue));
	printf("%s\n", dequeue(queue));
	enqueue(queue, a);
	printf("%d\n", isEmpty(queue));
	queue = queueInit();
	printf("isEmpty A: %d\n", isEmpty(queue));
	enqueue(queue, a);
	printf("isEmpty B: %d\n", isEmpty(queue));
	enqueue(queue, b);
	enqueue(queue, c);
	enqueue(queue, d);

	printf("Peek: %s\n", peek(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Peek: %s\n", peek(queue));
	printf("isEmpty C: %d\n", isEmpty(queue));

	return (0);
}



// Function used for the test
// Don't go further :)

