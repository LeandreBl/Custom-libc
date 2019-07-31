/*
** EPITECH PROJECT, 2018
** lbl-libc
** File description:
** header
*/

#ifndef LBL_LIBC_H_
#define LBL_LIBC_H_

#ifdef __cplusplus
extern "C" {
#endif
/* only here to remove the automatic fcking emacs indentation, Best regards */
#ifdef __horriblethingwithemacs
}
#endif

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <arpa/inet.h>

/* wrapper on read */
ssize_t wread(int fd, void *dest, size_t count);

/* free the n given pointers */
void nfree(size_t n, ...);

/*
** Return a server socket on port <port> and fills <buffer>
** <backlog> argument defines the length of the kernel pending queue and fills <buffer>
** Returns -1 on error
*/
int create_server(uint16_t port, int backlog, struct sockaddr_in *buffer);

/*
** Return a socket when a new client is connected, <sockfd> is the server fd
** Returns -1 on error
*/
int accept_client(int sockfd, struct sockaddr_in *buffer);

/*
** Try to connect to the server <ip> on <port> and return a client socket and fills <buffer>
** Return -1 on error
*/
int connect_to(const char *ip, uint16_t port, struct sockaddr_in *buffer);

/*
** Isacmd returns 1 if the cmd exist in $PATH
** return 0 otherwise
*/
bool isacmd(const char *str);

/*
** Returns the ip of the interface, if interface is NULL,
** returns the first valid ip it finds
** Return NULL on error
*/
char *get_ip(const char *interface);
uint32_t get_pub_ip(void);

/* Safefree free the *ptr pointer and set the value to NULL, take the adress of a ptr*/
void sfree(void *ptraddr);

/*
** Saves the given tab line per line with a \n in the <pathname> file
** Return -1 on error
*/
int save_file(char **file, const char *pathname);

/*
** Replace all occurences of <str> in <src> by <repl>
** This function allocate memory in most cases
** Return NULL on error
*/
char *replace(char *src, const char *str, const char *repl);

/*
** Load an entire file and allocate the memory to store it
** Returns NULL on error
*/
void *file_data(const char *pathname);

/* Returns the byte corresponding to the ASCII binary representation given in parameter */
char bin_to_char(const char *binary);

/*
** Returns an allocated pointer that contain the ASCII representation of the given byte
** Returns NULL on error
*/
char *char_to_bin(char n);

/*
** Writes the given [size] bytes from [data] into the given
** [pathname] file
** Returns -1 on error
*/
int save_as(const char *pathname, const void *data, size_t size);

/*
** Removes all <str> occurences inside of <src>
** remove_str("test", "t") will change the bytes stored into [src]
** giving "es\0\0\0", this function foes not allocate memory
** returns -1 on error
*/
int remove_str(char *src, const char *del);

/*
** Sort the given [tab] in ascending order using strcmp
** Returns 0
*/
int sort_tab(char **tabptr);

/*
** Load all filenames that are into the [dirname] directory
** into an allocated NULL terminated tab
** Returns NULL on error
*/
char **dir_filenames(const char *dirname, bool sort);

/*
** Insert str into src, moving the content so no byte is lose.
** If pos > strlen(src) it will allocate enough memory to store str
** at str + pos, each non initialized character between those 2 ptr is set to 0
** This function free the given char *src
** if str == NULL, returns src, if src == NULL returns NULL
** Returns NULL on error
*/
char *insert(char *src, const char *str, int pos);

/*
** Uses Xclip and system call to add the given [str] ptr into your clipboard
** using the X environnement
** Returns -1 on error
*/
int add_to_clipboard(const char *str);

/*
** Returns the amount of times the [cmp] characters is present in the
** \0 terminated [s] string
** Returns -1 on error
*/
int nb_of(const char *s, char cmp);

/*
** Displays the inside of the pointed [buf] memory first [size] bytes
** format can be either "%c" or "%d"
** "%c" displays the character instead of the value of the byte
** if this one is displayable (not negative values for example)
** "%d" will displays the values that are inside each bytes
** The display format is [<byte1>][<byte2>][<byte3>] ...
** Returns -1 on error
*/
int display_inside(const void *buf, const char *format, size_t size);

/* Returns the largest strlen(tab[i]) found into the NULL terminated tab */
int max_len(char **tabptr);

/*
** Same as strdup but for a tab, it is NULL terminated
** Returns NULL on error
*/
void *tabdup(void *tabptr);

/*
** Returns an allocated tab containing the [pathname] file
** tab[0] will contain the first [pathname] file line
** the original '\n' is replaced with a 0
** Returns NULL on error
*/
char **load_file(const char *pathname);

/*
** Returns the given [pathname] file size using read to avoid STAT(2)
** Returns -1 on error
*/
int file_size(const char *pathname);

/*
** Revert all positions of the strings inside of the given tab
** tab[0] became tab[LAST] ...
** Returns -1 on error
*/
int revtab(void *tabptr);

/*
** Frees the given tab ptr and store the previous values inside a new
** allocated tab, that will contain 1 more place to store the given [add]
** if [tab] is NULL, it returns an allocated tab that contains
** [add] in index 0
** The tab is NULL terminated
** Returns NULL on error
*/
void *tab_append(void *tab, void *add);
int append(void *tabaddr, void *add);
/*
** This function remove the char * at tab[index] and frees it
** without letting a blank by moving the other indexes
** This function does not allocate memory
** return -1 on Error
**
*/
int tab_remove(void *tabaddr, int index);

/*
** Returns 1 if the end of the [s] string match the
** [end] string like end_with("foo.mp3", ".mp3);
** Returns 0 if not :)
*/
bool end_with(const char *s, const char *end);

/*
** Kinda same as frealloc but with a tab, so you can add
** more space to store more pointers,
** Return NULL on error
*/
void *tab_realloc(void *tabptr, int add);

/* Create a fully allocated array of strings delimited by <delim> */
char **wordtab(const char *s, const char *delim);

/*
** shift_left("foo", 1) gives "oo\0\0"
** Returns -1 on error
*/
void shift_left(char *s, int n);

/*
** shift_right("foo", 1) gives "fo\0\0"
** Returns -1 on error
*/
void shift_right(char *s, int n);

char *get_next_line(int fd);

/*
** Returns an allocated string containing the ASCII representation
** of the given int, same as catalloc("%d", ..);
** Returns NULL on error
**/
char *int_char(int nb);

/*
** Returns the additionned strlen of all strings of the tab
** Returns -1 on error
*/
size_t total_len(char **tab);

/*
** Puts all strings of the given tab into a single one,
** one after the other.
** Returns NULL on error
*/
char *tab_to_str(char **tab);

/*
** Returns the size that the int would take in the memory if it was
** stored in his ASCII representation,
** int_len(-42) returns 3, for strlen("-42")
*/
int intlen(int nb);

/* Free the given type_ **tab */
void free_tab(void *tab);

/*
** Same but you need to pass the address of tab,
** it uses free_tab, and set the value of tab to NULL
*/
void sfree_tab(void *tabaddr);

/*
** Allocate a tab with [nlines] lines of [nlength] size each one
** They are all allocated and each byte is set to 0
** The tab is NULL terminated
** Returns NULL on error
*/
void *alloc_tab(size_t nlines, size_t nlength);

char *convert_endian_str(int fbyte);

int convert_endian(int fbyte);

/*
** Removes all useless spaces and \t of a string
** Does not allocate
** Uses shift_left/right
** Returns -1 on error
*/
int epur_str(char *str);

int total_name(const char *str);

size_t kstrlen(const char *str, char k);
size_t knstrlen(const char *str, char k, size_t n);

/* Reverse the order of the characters in str */
char *revstr(char *str);

/* Returns the size of a NULL terminated tab */
size_t tablen(void *tabptr);

/* Put a tab using \n for each lines */
void put_tab(char **tabptr);

/* Puts each line of tab till NULL preceded by <start> and followed by <end> */
void put_tabw(const char *start, char **tabptr, const char *end);

#ifdef __cplusplus
}
#endif

#endif /* !LBL_LIBC_H_ */
