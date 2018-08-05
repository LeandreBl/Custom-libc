/*
** my_tablen.c for tablen in /home/leandre
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Feb 24 16:24:34 2017 Léandre Blanchard
** Last update Sun Jan  7 11:08:49 2018 Léandre Blanchard
*/

#include "lbl-libc.h"

size_t tablen(void *ptr)
{
	size_t i;
	char **tab;

	i = 0;
	tab = ptr;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}
