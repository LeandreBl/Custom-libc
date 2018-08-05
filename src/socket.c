/*
** EPITECH PROJECT, 2017
** libc
** File description:
** socket C simple API
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

static int bind_and_get(int fd, struct sockaddr *server)
{
	socklen_t len = sizeof(server);

	if (bind(fd, server, sizeof(struct sockaddr_in)) == -1) {
		close(fd);
		return (-1);
	}
	if (getsockname(fd, server, &len) == -1)
		return (-1);
	return (0);
}

int create_server(uint16_t port, int backlog, struct sockaddr_in *buffer)
{
	struct sockaddr_in server;
	int fd;

	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1)
		return (-1);
	memset(&server, 0, sizeof(server));
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	if (bind_and_get(fd, (struct sockaddr *)&server) == -1 ||
		listen(fd, backlog) == -1)
		return (-1);
	if (buffer != NULL)
		*buffer = server;
	return (fd);
}

int accept_client(int sockfd, struct sockaddr_in *buffer)
{
	socklen_t clilen;
	struct sockaddr_in client;
	int fd;

	clilen = sizeof(client);
	fd = accept(sockfd, (struct sockaddr *)&client, &clilen);
	if (fd == -1)
		return (-1);
	if (buffer != NULL)
		*buffer = client;
	return (fd);
}

int connect_to(const char *ip, uint16_t port, struct sockaddr_in *buffer)
{
	struct hostent *info;
	struct sockaddr_in saddr;
	int fd;

	info = gethostbyname(ip);
	if (info == NULL)
		return (-1);
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1)
		return (-1);
	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_addr = *(struct in_addr *)info->h_addr;
	saddr.sin_port = htons(port);
	saddr.sin_family = AF_INET;
	if (connect(fd, (struct sockaddr *)&saddr, sizeof(saddr)) == -1) {
		close(fd);
		return (-1);
	}
	if (buffer != NULL)
		*buffer = saddr;
	return (fd);
}
