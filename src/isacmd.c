/*
** EPITECH PROJECT, 2017
** isacmd
** File description:
** if str is a binary
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <lbl-libc.h>

static bool try_each(char **paths, char *cmd)
{
	char *p;

	for (size_t i = 0; paths[i]; ++i) {
		p = paths[i];
		if (asprintf(&paths[i], "%s/%s", paths[i], cmd)
			&& access(paths[i], F_OK) == 0) {
			free(p);
			sfree_tab(&paths);
			return (false);
		}
		free(p);
	}
	sfree_tab(&paths);
	free(cmd);
	return (false);
}

bool isacmd(const char *str)
{
	char *env;
	char **paths;
	char *cmd;

	env = getenv("PATH");
	paths = wordtab(env, ":");
	cmd = strndup(str, kstrlen(str, ' '));
	if (env == NULL || paths == NULL || cmd == NULL)
		return (false);
	return (try_each(paths, cmd));
}
