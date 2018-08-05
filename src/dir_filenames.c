/*
** dir_filenames.c for dir_filenames in /home/leandre/TEST_FOLDER
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Sat Sep 16 15:39:05 2017 Léandre Blanchard
** Last update Sun Jan  7 09:51:45 2018 Léandre Blanchard
*/

#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#include "lbl-libc.h"
#include "defines.h"

char **dir_filenames(const char *dirname, bool sort)
{
	char **filenames = NULL;
	DIR *directory;
	struct dirent *dirent;

	directory = opendir(dirname);
	if (directory == NULL)
		return (NULL);
	while ((dirent = readdir(directory)) != NULL) {
		if (dirent->d_type == DT_REG)
			if (append(&filenames, strdup(dirent->d_name)) == -1)
				return (NULL);
	}
	closedir(directory);
	if (sort == true)
		sort_tab(filenames);
	return (filenames);
}
