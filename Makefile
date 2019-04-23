# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:41:01 by oadhesiv          #+#    #+#              #
#    Updated: 2019/04/23 16:45:51 by oadhesiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNCTIONS_PART1 = memset bzero memcpy memccpy memmove memchr memcmp \
				strlen strdup strcpy strncpy strcat strncat strlcat strchr \
				strrchr strstr strnstr strcmp strncmp \
				atoi isalpha isdigit isalnum isascii isprint \
				toupper tolower

FUNCTIONS_PART2 = memalloc memdel \
				strnew strdel strclr striter striteri strmap strmapi strequ \
				strnequ strsub strjoin strtrim strsplit \
				itoa \
				putchar putstr putendl putnbr \
				putchar_fd putstr_fd putendl_fd putnbr_fd

FUNCTIONS_BONUS = lstnew lstdelone lstdel lstadd lstiter lstmap

FUNCTIONS_PRSNL = print_memory strrev ltoa_static ltoa

FUNCTIONS = $(FUNCTIONS_PART1)\
			$(FUNCTIONS_PART2)\
			$(FUNCTIONS_BONUS)\
			$(FUNCTIONS_PRSNL)

OBJECTS = $(patsubst %,objs/ft_%.o,$(FUNCTIONS))
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c,objs/%.o,$(SOURCES))
OBJ_DIR = ./objs

FLAGS = -Wall -Wextra -Werror -O3 -funroll-loops
SOFLAGS = -fPIC -shared

NAME = libft.a
DYNN = libft.so

CC = gcc

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

so: $(OBJECTS)
	$(CC) $(SOFLAGS) -o $(DYNN) $(OBJECTS)

objs/%.o: %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)
	rm -rfv objs

fclean: clean
	rm -f $(NAME) $(DYNN)

re: fclean all

.PHONY: all clean fclean re so
