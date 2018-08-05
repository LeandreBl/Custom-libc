/*
** my_revstr.c for my_revstr in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.eu
**
** Started on  Fri Oct  7 11:01:26 2016 Leandre Blanchard
** Last update Sun Jan  7 11:02:53 2018 Léandre Blanchard
*/

#include <string.h>

#include "defines.h"

char *revstr(char *str)
{
	char c;
	int len;

	if (str == NULL)
		return (NULL);
	len = sstrlen(str);
	for (int i = 0; i < len / 2; ++i) {
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return (str);
}
