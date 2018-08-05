##
## EPITECH PROJECT, 2017
##
## File description:
## makefile
##

NAME		= liblbl-libc.so

CC		= gcc

SRCS		= src/char_binary.c
SRCS		+= src/clipboard.c
SRCS		+= src/convert_endian.c
SRCS		+= src/dir_filenames.c
SRCS		+= src/display_inside.c
SRCS		+= src/end_with.c
SRCS		+= src/epur_str.c
SRCS		+= src/free_tab.c
SRCS		+= src/get_ip.c
SRCS		+= src/insert.c
SRCS		+= src/max_len.c
SRCS		+= src/alloc_tab.c
SRCS		+= src/intlen.c
SRCS		+= src/revstr.c
SRCS		+= src/sstrlen.c
SRCS		+= src/wordtab.c
SRCS		+= src/total_len.c
SRCS		+= src/nb_of.c
SRCS		+= src/put_tab.c
SRCS		+= src/realloc.c
SRCS		+= src/remove_str.c
SRCS		+= src/replace.c
SRCS		+= src/revtab.c
SRCS		+= src/save_as.c
SRCS		+= src/save_file.c
SRCS		+= src/sfree.c
SRCS		+= src/shift.c
SRCS		+= src/sort_tab.c
SRCS		+= src/tab_append.c
SRCS		+= src/tabdup.c
SRCS		+= src/tablen.c
SRCS		+= src/total_name.c
SRCS		+= src/isacmd.c
SRCS		+= src/socket.c
SRCS		+= src/read_wrapper.c
SRCS		+= src/load_file.c

TESTS_SRCS	:= $(SRCS)

OBJS		= $(SRCS:.c=.o)
TESTS_OBJS	= $(TESTS_SRCS:.c=.o)

RM		= rm -f

CFLAGS		= -Werror -Wall -Wextra -fPIC -pedantic
CFLAGS		+= -I ./include
LDFLAGS		= -shared

GREEN		= '\033[0;32m'
NO_COLOR	= '\033[0m'

%.o : %.c
	@$ $(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CC) $(CFLAGS) -c $< -o $@ ["$(GREEN)"OK"$(NO_COLOR)"]"
.SUFFIXES: .o .c

all: $(NAME)

$(NAME): $(OBJS)
	@$ $(CC) $(LDFLAGS) $(OBJS) -o $@
	@echo "$(CC) $(LDFLAGS) $(OBJS) -o $@ \
	["$(GREEN)"LINKING OK"$(NO_COLOR)"]"

tests_run: $(TESTS_OBJS)
	@$ $(CC) -lcriterion $(TESTS_OBJS) -o $@
	@echo "$(CC) -lcriterion $(TESTS_OBJS) -o $@ \
	["$(GREEN)"LINKING OK"$(NO_COLOR)"]"
	./$@
	@$(RM) $@
	@$(RM) $(TESTS_OBJS)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

install: re
	@cp $(NAME) /usr/lib/$(NAME) 2> /dev/null || \
	printf "\033[1m\033[31mError : try sudo make install\033[0m\n" && \
	cp include/lbl*.h /usr/include/ 2> /dev/null && \
	printf "\033[1m\033[32mLibrary successfull installed !\033[0m\n"

.PHONY: all clean fclean re tests_run debug install
