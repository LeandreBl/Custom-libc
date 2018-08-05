/*
** EPITECH PROJECT, 2018
** custom libc
** File description:
** file _size
*/

#include <sys/stat.h>

int file_size(const char *pathname)
{
	struct stat stats;

	if (stat(pathname, &stats) == -1)
		return (-1);
	return (stats.st_size);
}
