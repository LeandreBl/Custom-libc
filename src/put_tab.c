/*
** my_put_tab.c for put_tab in /home/leandre
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Feb 24 16:25:21 2017 Léandre Blanchard
** Last update Sun Jan  7 10:41:06 2018 Léandre Blanchard
*/

#include <stdio.h>

void put_tab(char **tab)
{
	if (tab == NULL)
		printf("{ NULL }\n");
	else
		for (size_t i = 0; tab[i]; ++i)
			printf("%s\n", tab[i]);
}

void put_tabw(const char *start, char **tab, const char *end)
{
	if (tab == NULL)
		printf("{ NULL }");
	else
		for (size_t i = 0; tab[i]; ++i)
			printf("%s%s%s\n", start, tab[i], end);
}
