/*
** display_inside.c for display_inside in /home/leandre/TEST_FOLDER
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Mon Jul  3 18:47:09 2017 Léandre Blanchard
** Last update Sun Jan  7 09:52:15 2018 Léandre Blanchard
*/

#include <string.h>
#include <stdio.h>

static int case_digit(const char *dup, size_t size)
{
	size_t i;

	i = 0;
	while (i < size) {
		printf("[%d]", dup[i]);
		i++;
	}
	return (0);
}

static int case_character(const char *dup, size_t size)
{
	size_t i;

	i = 0;
	while (i < size) {
		if (dup[i] >= ' ' && dup[i] <= 126)
			printf("['%c']", dup[i]);
		else if (dup[i] == '\n')
			printf("['\\n']");
		else
			printf("[%d]", dup[i]);
		i++;
	}
	return (0);
}

int display_inside(const void *buf, const char *format, size_t size)
{
	const char *dup;

	if (buf == NULL)
		return (printf("*NULL*"));
	dup = (char *)buf;
	if (strcmp(format, "%c") == 0)
		return (case_character(dup, size));
	else if (strcmp(format, "%d") == 0)
		return (case_digit(dup, size));
	return (0);
}
