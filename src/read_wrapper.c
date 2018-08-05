/*
** EPITECH PROJECT, 2018
** read wrapper
** File description:
** wrapper on read syscall
*/

#include <unistd.h>

ssize_t wread(int fd, void *dest, size_t count)
{
	ssize_t rd;
	size_t total = 0;
	char *ptr = dest;

	do {
		rd = read(fd, ptr + total, count - total);
		if (rd == -1 || (rd == 0 && count - total != 0))
			return (rd);
		total += rd;
	} while (total < count);
	return (total);
}
