/*
** remove_str.c for remove_char in /home/leandre/lbl-libc/C
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Sep  8 10:03:54 2017 Léandre Blanchard
** Last update Sun Jan  7 11:02:04 2018 Léandre Blanchard
*/


#include <string.h>

#include "lbl-libc.h"

int remove_str(char *src, const char *del)
{
	char *pos;
	int len;

	len = strlen(del);
	while ((pos = strstr(src, del)) != NULL)
		shift_left(pos, len);
	return (0);
}
