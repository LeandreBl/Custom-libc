/*
** save_file.c for save_file in /home/lblanchard/lbl-libc/C
**
** Made by Leandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Oct 13 11:06:20 2017 Leandre Blanchard
** Last update Sun Jan  7 13:21:25 2018 Léandre Blanchard
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int save_file(char **tab, const char *pathname)
{
	int fd;

	fd = open(pathname, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		return (-1);
	for (int i = 0; tab[i]; ++i) {
		write(fd, tab[i], strlen(tab[i]));
		write(fd, "\n", 1);
	}
	close(fd);
	return (0);
}
