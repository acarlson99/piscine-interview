/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:04:46 by acarlson          #+#    #+#             */
/*   Updated: 2019/06/18 11:05:09 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	rec(int target, struct s_array *array, int total) {
	int i = 0;

	if (total >= target) {
		if (total == target)
			arrayPrint(array);
		return ;
	}
	while (i < target) {
		if (target - i <= 0)
			break ;
		else if (total + (target - i) > target) {
			++i;
			continue ;
		}
		arrayAppend(array, target - i);
		rec(target, array, total + (target - i));
		--array->length;
		++i;
	}
}

void	printPossibleSlices(int pizzaSize) {
	struct s_array *array = arrayInit();

	rec(pizzaSize, array, 0);
}
