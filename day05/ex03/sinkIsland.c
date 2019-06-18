/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:58:54 by acarlson          #+#    #+#             */
/*   Updated: 2019/06/18 13:30:54 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sinkIsland(int **map, int row, int col) {
	if (!map || !map[row] || map[row][col] != 1)
		return ;
	map[row][col] = 0;
	sinkIsland(map, row + 1, col);
	sinkIsland(map, row - 1, col);
	sinkIsland(map, row, col + 1);
	sinkIsland(map, row, col - 1);
}
