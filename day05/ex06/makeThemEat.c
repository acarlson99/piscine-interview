/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:43:58 by acarlson          #+#    #+#             */
/*   Updated: 2019/06/18 17:19:18 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

#define CONTIF(cond) if (cond) continue
#define RETIF(cond, val) if (cond) return (val)

int seekEnd(char *table, int totalTime) {
	for (int i = 0; ; ++i)
		RETIF(!(i <= totalTime && table[i]), i);
}

int arrMod(struct s_people *person, char *table, int b, int totalTime) {
	int end = seekEnd(table, totalTime);

	RETIF((end < 0 || end + person->time > totalTime), 0);
	for (int i = end; i < person->time; ++i)
		table[end + (i * (b ? 1 : -1))] = !!b;
	return (1);
}

int butRllyTho(struct s_people **people, char **tables, int totalTime,
				int fst) {
	RETIF(!*people, 1);
	for (int i = 0; people[i]; ++i) {
		for (int tab = 0; tables[tab] && (!fst || i < fst); ++tab) {
			CONTIF(!arrMod(people[i], tables[tab], 1, totalTime));
			RETIF(butRllyTho(people + (i + 1), tables, totalTime, 0), 1);
			arrMod(people[i], tables[tab], 0, totalTime);
		}
	}
	return (0);
}

int	isPossible(struct s_people **people, int nbTable, int totalTime) {
	char **tables = calloc(nbTable + 1, sizeof(char*));

	for (int i = 0; i < nbTable; ++i)
		tables[i] = calloc(totalTime + 1, sizeof(char));
	return (butRllyTho(people, tables, totalTime, 1));
}
