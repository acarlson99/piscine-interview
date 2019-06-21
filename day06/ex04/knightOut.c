#include <math.h>
#include <stdlib.h>
#include "header.h"

#define NUMMOVES 8
#define BOARDWIDTH 8

int getInitialPos(uint64_t board) {
	double r = log2(board);
	if (modf(r, &r))
		return (~0);
	return ((int)r);
}

double knightOut(uint64_t board, int n) {
	if (n > 100)
		return (1.);
	int pos = getInitialPos(board);
	if (n < 1 || pos < 0)
		return (-1.);
	double hashtbl[8][8][n+1];
	int movi[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int movj[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

	for (int i = 0; i < BOARDWIDTH; ++i) {
		for (int j = 0; j < BOARDWIDTH; ++j) {
			hashtbl[i][j][0] = 1;
		}
	}

	for (int step = 1; step <= n; ++step) {
		for (int i = 0; i < BOARDWIDTH; ++i) {
			for (int j = 0; j < BOARDWIDTH; ++j) {
				double total = 0.;
				for (int mov = 0; mov < NUMMOVES; ++mov) {
					int newi = (i + movi[mov]);
					int newj = (j + movj[mov]);

					if (newi > 7 || newi < 0 || newj > 7 || newj < 0)
						continue ;
					else
						total += hashtbl[newi][newj][step-1] / 8.;
				}
				hashtbl[i][j][step] = total;
			}
		}
	}
	int target_i = pos / BOARDWIDTH;
	int target_j = pos % BOARDWIDTH;
	return (1. - hashtbl[target_i][target_j][n]);
}
