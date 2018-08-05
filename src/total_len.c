/*
** my_total_len.c for my_total_len in /home/leandre/libmy
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Thu Mar 23 22:35:06 2017 Léandre Blanchard
** Last update Sun Jan  7 10:40:17 2018 Léandre Blanchard
*/

#include <stdlib.h>
#include <string.h>

#include "lbl-libc.h"

size_t total_len(char **tab)
{
	size_t len = 0;

	for (size_t i = 0; tab[i]; ++i)
		len += strlen(tab[i]);
	return (len);
}

char *tab_to_str(char **tab)
{
	size_t len = total_len(tab);
	char *line = calloc(len + 1, sizeof(char));
	size_t tlen = tablen(tab);

	for (size_t i = 0; i < tlen; ++i)
		strcat(line, tab[i]);
	return (line);
}
