/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationsV2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:32:27 by acarlson          #+#    #+#             */
/*   Updated: 2019/06/18 14:23:58 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

void	printBois(char *str, size_t len, size_t idx, char *buffer,
				struct s_dict *dict) {
	size_t i = -1;

	if (idx == len) {
		if (dictSearch(dict, buffer) == -1 && dictInsert(dict, buffer, 1))
			puts(buffer);
		return ;
	}
	while (++i < len) {
		if (str[i]) {
			buffer[idx] = str[i];
			str[i] = '\0';
			printBois(str, len, idx + 1, buffer, dict);
			str[i] = buffer[idx];
			buffer[idx] = '\0';
		}
	}
}

void	printUniquePermutations(char *str) {
	if (!str)
		return ;
	int len = strlen(str);

	printBois(str, len, 0, calloc((len + 1), sizeof(char)), dictInit(len));
}
