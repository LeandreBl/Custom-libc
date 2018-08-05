/*
** insert.c for insert in /home/leandre/TEST_FOLDER
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Wed Sep  6 16:57:05 2017 Léandre Blanchard
** Last update Sun Jan  7 10:32:01 2018 Léandre Blanchard
*/

#include <stdlib.h>
#include <string.h>

#include "defines.h"
#include "lbl-libc.h"

static char *too_far(char *src, const char *str, int pos)
{
	char *dest;

	dest = calloc(pos + sstrlen(str) + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	strcpy(dest, src);
	strcpy(dest + pos, str);
	free(src);
	return (dest);
}

char *insert(char *src, const char *str, int pos)
{
	char *dest;
	int len;

	if (str == NULL || src == NULL)
		return (src);
	len = sstrlen(src);
	if (pos > len)
		return (too_far(src, str, pos));
	dest = calloc(len + sstrlen(str) + 2, sizeof(char));
	if (dest == NULL)
		return (NULL);
	strncpy(dest, src, pos);
	strcpy(dest + pos, str);
	strcpy(dest + pos + sstrlen(str), src + pos);
	free(src);
	return (dest);
}
