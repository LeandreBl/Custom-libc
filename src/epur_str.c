/*
** epur_str.c for epur_str in /home/leandre/libmy
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Mon Mar 13 14:38:15 2017 Léandre Blanchard
** Last update Sun Jan  7 09:52:41 2018 Léandre Blanchard
*/

#include <string.h>

#include "defines.h"
#include "lbl-libc.h"

int epur_str(char *str)
{
	int i;

	for (i = 0; str[i] == ' ' || str[i] == '\t'; ++i)
		shift_left(str, 1);
	while (str[i] != 0) {
		while ((str[i] == ' ' || str[i] == '\t')
		       && (str[i + 1] == ' ' || str[i + 1] == '\t'))
			shift_left(str + i, 1);
		++i;
	}
	if (sstrlen(str) > 0)
		while (str[sstrlen(str) - 1] == ' '
		       || str[sstrlen(str) - 1] == '\t')
			shift_right(str, 1);
	return (0);
}
