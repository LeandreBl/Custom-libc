/*
** EPITECH PROJECT, 2018
** custom libc
** File description:
** load file
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "lbl-libc.h"

char **load_file(const char *pathname)
{
	char **tab = NULL;
	char *input = NULL;
	int size;
	int fd;

	size = file_size(pathname);
	fd = open(pathname, O_RDONLY);
	if (fd != -1 && size != -1) {
		input = calloc(size + 2, sizeof(char));
		if (input == NULL || read(fd, input, size) == -1)
			return (NULL);
		if (input[strlen(input) - 1] != '\n')
			input[strlen(input)] = '\n';
		close(fd);
		tab = wordtab(input, "\n");
		free(input);
	}
	return (tab);
}
