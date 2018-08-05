/*
** my_alloc_tab.c for alloc_tab in /home/leandre/Games/Tetris
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Mar 17 18:13:15 2017 Léandre Blanchard
** Last update Sun Jan  7 10:04:39 2018 Léandre Blanchard
*/

#include <stdlib.h>

#include "lbl-libc.h"

void *alloc_tab(size_t nlines, size_t nlength)
{
	void **tab = calloc(nlines + 1, sizeof(char));

	if (tab) {
		for (size_t i = 0; i < nlength; ++i) {
			tab[i] = calloc(nlength, sizeof(char));
			if (!tab[i]) {
				sfree_tab(&tab);
				return (NULL);
			}
		}
	}
	return (tab);
}
