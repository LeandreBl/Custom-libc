/*
** max_len.c for max_len in /home/leandre
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Thu May 25 19:55:56 2017 Léandre Blanchard
** Last update Sun Jan  7 10:03:36 2018 Léandre Blanchard
*/

#include <string.h>

int max_len(char **tab)
{
	size_t max = 0;
	size_t len;

	for (int i = 0; tab[i]; ++i) {
		len = strlen(tab[i]);
		if (len > max)
			max = len;
	}
	return (max);
}
