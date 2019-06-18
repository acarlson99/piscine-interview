/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:08:36 by acarlson          #+#    #+#             */
/*   Updated: 2019/06/18 13:30:11 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	max_(double a, double b) {
	return (a > b ? a : b);
}

double	rec(int n, double currentPrice, double *prices) {
	double max = currentPrice;
	int i = 0;
	
	while (++i <= n)
		max = max_(rec(n - i, currentPrice + prices[i], prices), max);
	return (max);
}

double	bestPrice(int pizzaSize, double *prices) {
	return (rec(pizzaSize, 0., prices));
}
