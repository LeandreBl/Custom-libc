/*
** tab_append.c for tab_append in /home/leandre
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Sun May 14 20:03:11 2017 Léandre Blanchard
** Last update Sun Jan  7 11:08:10 2018 Léandre Blanchard
*/

#include <stdlib.h>

#include "lbl-libc.h"

int tab_remove(void *ptr, int index)
{
	void **tab = ptr;
	void *store;

	if (tab == NULL || index < 0 || index > (int)tablen(tab))
		return (-1);
	store = tab[index];
	for (int i = index; tab[i] != NULL; ++i)
		tab[i] = tab[i + 1];
	free(store);
	return (0);
}

void *tab_append(void *ptr, void *add)
{
	void **tab = ptr;
	size_t len = tablen(tab);
	void **new = calloc(len + 2, sizeof(void *));

	if (!new)
		return (NULL);
	if (tab)
		for (size_t i = 0; tab[i]; ++i)
			new[i] = tab[i];
	new[len] = add;
	free(tab);
	return (new);
}

int append(void *ptr, void *add)
{
	*(void ***)ptr = tab_append(*(void ***)ptr, add);
	if (*(void ***)ptr == NULL)
		return (-1);
	return (0);
}
