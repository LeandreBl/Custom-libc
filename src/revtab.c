/*
** rev_tab.c for rev_tab in /home/leandre/libmy
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Thu May 25 19:13:10 2017 Léandre Blanchard
** Last update Sun Jan  7 11:03:21 2018 Léandre Blanchard
*/

#include <stdlib.h>

#include "lbl-libc.h"

int revtab(void *ptr)
{
	int i;
	int len;
	char **tab;
	char *temp;

	tab = ptr;
	if (tab == NULL)
		return (-1);
	len = tablen(tab);
	i = 0;
	while (i != len / 2) {
		temp = tab[i];
		tab[i] = tab[len - 1 - i];
		tab[len - 1 - i] = temp;
		i++;
	}
	return (0);
}
