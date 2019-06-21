#include <stdio.h>
#include "header.h"

#define P_g (1. / 37.)
#define R_g(n) (n / 2.)
#define P_r (18. / 37.)
#define R_r(n) (n * 2.)
#define P_b (18. / 37.)
#define R_b(n) (0.)

#define MAXDEPTH 15

double f(double firstDollarsBet, double dollarsWanted, int nbGame, int depth) {
	if (nbGame <= 0 || firstDollarsBet >= dollarsWanted || firstDollarsBet == 0 || depth >= MAXDEPTH)
		return (firstDollarsBet >= dollarsWanted);
	return ((f(R_g(firstDollarsBet), dollarsWanted, nbGame - 1, depth + 1) * P_g)
			+ (f(R_r(firstDollarsBet), dollarsWanted, nbGame - 1, depth + 1) * P_r)
			+ (f(R_b(firstDollarsBet), dollarsWanted, nbGame - 1, depth + 1) * P_b));
}

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame) {
	return (f(firstDollarsBet, dollarsWanted, nbGame, 0));
}
