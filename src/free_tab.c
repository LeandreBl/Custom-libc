/*
** free_tab.c for free_tab in /home/leandre/libmy/
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Tue Feb 28 14:14:05 2017 Léandre Blanchard
** Last update Sun Jan  7 09:54:34 2018 Léandre Blanchard
*/

#include <stdlib.h>

#include "lbl-libc.h"

void sfree_tab(void *tabaddr)
{
	free_tab(*(void ***)tabaddr);
	*(void ***)tabaddr = NULL;
}

void free_tab(void *tab)
{
	void **ptr = tab;

	if (!ptr)
		return;
	for (size_t i = 0; ptr[i]; ++i)
		free(ptr[i]);
	free(ptr);
}
