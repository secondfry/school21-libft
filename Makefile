# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:41:01 by oadhesiv          #+#    #+#              #
#    Updated: 2019/07/12 17:47:16 by oadhesiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LFT_FUNCTIONS_PART1 = memset bzero memcpy memccpy memmove memchr memcmp \
	strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr \
	strnstr strcmp strncmp \
	atoi \
	isalpha isdigit isalnum isascii isprint \
	toupper tolower

LFT_FUNCTIONS_PART2 = memalloc memdel \
	strnew strdel strclr striter striteri strmap strmapi strequ strnequ \
	strsub strjoin strtrim strsplit \
	itoa \
	putchar putstr putendl putnbr \
	putchar_fd putstr_fd putendl_fd putnbr_fd

LFT_FUNCTIONS_BONUS = lstnew lstdelone lstdel lstadd lstiter lstmap

LFT_FUNCTIONS_PRSNL = atol ltoa ltoa_static ltoa_hex_static \
	putlong putlong_fd putchar_color putstr_color \
	print_ptr print_memory print_list \
	strrev strtol \
	isspace

LFT_FUNCTIONS = $(LFT_FUNCTIONS_PART1)\
				$(LFT_FUNCTIONS_PART2)\
				$(LFT_FUNCTIONS_BONUS)\
				$(LFT_FUNCTIONS_PRSNL)

FUNCTIONS = get_next_line \
	byte_array_new byte_array_resize byte_array_add byte_array_has

OBJECTS = 	$(patsubst %,objs/ft_%.o,$(LFT_FUNCTIONS)) \
			$(patsubst %,objs/%.o,$(FUNCTIONS))

OBJ_DIR = ./objs

FLAGS = -Wall -Wextra -Werror -O1 -funroll-loops
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
