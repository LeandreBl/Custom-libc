/*
** sstrlen.c for sstrlen in /home/lblanchard/CPool_Day04
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Thu Oct  6 19:01:09 2016 Leandre Blanchard
** Last update Mon Jan  1 12:10:05 2018 Léandre Blanchard
*/

#include <stdlib.h>
#include <string.h>

size_t kstrlen(const char *str, char k)
{
	size_t i;

	i = 0;
	while (str[i] != k && str[i])
		++i;
	return (i);
}

size_t knstrlen(const char *str, char k, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && str[i] != k)
		++i;
	return (i);
}
