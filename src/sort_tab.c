/*
** sort_tab.c for sort_tab in /home/leandre/TEST_FOLDER
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Sat Sep 16 15:36:40 2017 Léandre Blanchard
** Last update Sun Jan  7 11:07:19 2018 Léandre Blanchard
*/

#include <string.h>

static int test_order(char **tab)
{
	if (!tab)
		return (0);
	for (int i = 0; tab[i + 1]; ++i) {
		if (strcmp(tab[i], tab[i + 1]) > 0)
			return (1);
	}
	return (0);
}

int sort_tab(char **tab)
{
	char *swap;

	while (test_order(tab)) {
		for (int i = 0; tab[i + 1]; ++i) {
			if (strcmp(tab[i], tab[i + 1]) > 0) {
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
		}
	}
	return (0);
}
