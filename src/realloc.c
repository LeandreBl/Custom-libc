/*
** realloc.c for mnishell in /home/leandre/System_unix/PSU_2016_minishell1
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Sat Jan 21 17:29:08 2017 Léandre Blanchard
** Last update Sun Jan  7 10:41:58 2018 Léandre Blanchard
*/

#include <stdlib.h>

#include "lbl-libc.h"

void *tab_realloc(void *src, int add)
{
	return (realloc(src, tablen(src) + add));
}
