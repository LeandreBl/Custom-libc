/*
** char_to_binary.c for car_to_binary in /home/leandre/TEST_FOLDER
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Tue Sep 12 15:37:45 2017 Léandre Blanchard
** Last update Tue Sep 12 15:41:18 2017 Léandre Blanchard
*/

#include <stdlib.h>

char *char_to_bin(char n)
{
	char *binary;

	binary = calloc(9, sizeof(char));
	if (!binary)
		return (NULL);
	for (size_t i = 0; i < 8 * sizeof(char); ++i) {
		if ((n << i) & 0x80)
			binary[i] = '1';
		else
			binary[i] = '0';
	}
	return (binary);
}

char bin_to_char(const char *binary)
{
	char n;

	n = 0;
	for (size_t i = 0; i < 8 * sizeof(char); ++i) {
		n <<= 1;
		if (binary[i] == '1')
			n ^= 1;
	}
	return (n);
}
