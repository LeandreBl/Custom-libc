/*
** tabdup.c for tabdup in /home/leandre/libmy
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Thu May 25 19:35:48 2017 Léandre Blanchard
** Last update Sun Jan  7 11:08:37 2018 Léandre Blanchard
*/

#include <stdlib.h>

#include "lbl-libc.h"

void *tabdup(void *tab)
{
	void **src = tab;
	size_t len = tablen(tab);
	void **new = calloc(len, sizeof(void *));

	if (!new)
		return (NULL);
	for (size_t i = 0; i < len; ++i)
		new[i] = src[i];
	return (new);
}
