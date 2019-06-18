/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:42:19 by acarlson          #+#    #+#             */
/*   Updated: 2019/06/18 14:38:08 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

double	max_(double a, double b) {
	return (a > b ? a : b);
}

double	rec(int n, double *prices, double *hashtablelol, int fst) {
	double max = 0.;
	int i = 0;
	double ret = 0;

	if (hashtablelol[n])
		return (hashtablelol[n]);
	while (++i <= n) {
		ret = rec(n - i, prices, hashtablelol, 0);
		max = max_(ret + prices[i], max);
	}
	hashtablelol[n] = max;
	if (fst)
		free(hashtablelol);
	return (max);
}

double	optimizedBestPrice(int pizzaSize, double *prices) {
	return (rec(pizzaSize, prices, calloc(pizzaSize + 1, sizeof(double)), 1));
}
