/*
** EPITECH PROJECT, 2018
** lbl-libc
** File description:
** nfree
*/

#include <stdlib.h>
#include <stdarg.h>

void nfree(size_t n, ...)
{
	va_list va;
	void *ptr;

	va_start(va, n);
	while (n > 0) {
		ptr = va_arg(va, void *);
		free(ptr);
		--n;
	}
	va_end(va);
}
