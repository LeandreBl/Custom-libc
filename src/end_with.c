/*
** end_with.c for end_with in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Wed May  3 13:21:06 2017 Léandre Blanchard
** Last update Sun Jan  7 09:52:22 2018 Léandre Blanchard
*/

#include <string.h>

#include "lbl-libc.h"
#include "defines.h"

bool end_with(const char *s, const char *end)
{
	size_t size;

	size = sstrlen(end);
	if (size > sstrlen(s))
		return (false);
	if (strcmp(s + sstrlen(s) - size, end) == 0)
		return (true);
	return (false);
}
