/*
** file_data.c for file_data in /home/leandre/TEST_FOLDER
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Tue Sep 12 20:01:55 2017 Léandre Blanchard
** Last update Sun Jan  7 10:27:07 2018 Léandre Blanchard
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "lbl-libc.h"

void *file_data(const char *pathname)
{
	void *data;
	int fd;
	int size;

	if (pathname == NULL)
		return (NULL);
	size = file_size(pathname);
	if (size == -1)
		return (NULL);
	if ((fd = open(pathname, O_RDONLY)) == -1)
		return (NULL);
	data = calloc(size, sizeof(char));
	if (data == NULL)
		return (NULL);
	if ((read(fd, data, size)) == -1)
		sfree(&data);
	close(fd);
	return (data);
}
