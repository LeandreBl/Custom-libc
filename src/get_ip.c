/*
** EPITECH PROJECT, 2017
** lbl-libc
** File description:
** get_ip
*/

#include <string.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

#include "lbl-libc.h"

static bool is_working_ip(const char *ip)
{
	return !(strcmp(ip, "0.0.0.0") || strcmp(ip, "127.0.0.1"));
}

char *get_ip(const char *interface)
{
	struct ifaddrs *ifaddr;
	struct ifaddrs *cursor;
	struct sockaddr_in *saddr;
	bool isfind = false;
	char *ip = calloc(17, sizeof(char));

	if (!ip || getifaddrs(&ifaddr) == -1)
		return (NULL);
	for (cursor = ifaddr; cursor; cursor = cursor->ifa_next) {
		if (cursor->ifa_addr
		    && cursor->ifa_addr->sa_family == AF_INET) {
			saddr = (struct sockaddr_in *)cursor->ifa_addr;
			strcpy(ip, inet_ntoa(saddr->sin_addr));
			if (!interface && is_working_ip(ip))
				break;
			if (interface && !strcmp(cursor->ifa_name, interface)) {
				isfind = true;
				break;
			}
		}
	}
	if (interface && !isfind)
		sfree(&ip);
	freeifaddrs(ifaddr);
	return (ip);
}

uint32_t get_pub_ip(void)
{
	FILE *stream;
	uint32_t addr = 0;
	char *line = NULL;
	char *temp;
	size_t n = 0;

	stream = popen("curl ipinfo.io/ip 2> /dev/null", "r");
	if (stream == NULL)
		return (0);
	getline(&line, &n, stream);
	temp = line;
	for (int i = 0; i < 4 && temp; ++i) {
		((char *)&addr)[i] = (char)atoi(temp);
		temp = strpbrk(temp + 1, "., ");
		if (temp)
			++temp;
	}
	pclose(stream);
	free(line);
	return (addr);
}
