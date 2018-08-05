/*
** clipboard.c for clipboard in /home/leandre/libmy
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Sun Jul 16 21:59:28 2017 Léandre Blanchard
** Last update Sun Jan  7 09:50:22 2018 Léandre Blanchard
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>

int add_to_clipboard(const char *str)
{
	char *new;

	if (asprintf(&new, "echo %s | xclip -selection clipboard", str) == -1)
		return (-1);
	system(new);
	free(new);
	if (asprintf(&new, "echo %s | xclip", str) == -1)
		return (-1);
	system(new);
	free(new);
	return (0);
}
