/*
** replace.c for replace in /home/lblanchard/TEST
**
** Made by Leandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Oct 13 10:33:07 2017 Leandre Blanchard
** Last update Sun Jan  7 11:02:34 2018 Léandre Blanchard
*/

#include <string.h>

#include "defines.h"
#include "lbl-libc.h"

char *replace(char *src, const char *str, const char *repl)
{
	char *pos;
	int prev;

	if (src == NULL || str == NULL || sstrlen(repl) == 0)
		return (src);
	pos = src;
	prev = 0;
	while ((pos = strstr(pos, str)) != NULL) {
		prev = pos - src;
		shift_left(pos, strlen(str));
		src = insert(src, repl, pos - src);
		if (src == NULL)
			return (NULL);
		pos = src + prev + 1;
	}
	return (src);
}
