/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:05:38 by acarlson          #+#    #+#             */
/*   Updated: 2019/06/18 13:26:57 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void printBois(char *str, size_t len, size_t idx, char *buffer) {
	size_t i = -1;

	if (idx == len) {
		puts(buffer);
		return ;
	}
	while (++i < len) {
		if (str[i]) {
			buffer[idx] = str[i];
			str[i] = '\0';
			printBois(str, len, idx + 1, buffer);
			str[i] = buffer[idx];
			buffer[idx] = '\0';
		}
	}
	if (!idx)
		free(buffer);
}

void printPermutations(char *str) {
	if (!str)
		return ;
	int len = strlen(str);

	printBois(str, len, 0, calloc((len + 1), sizeof(char)));
}
