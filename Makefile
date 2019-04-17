# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:41:01 by oadhesiv          #+#    #+#              #
#    Updated: 2019/04/04 17:59:08 by oadhesiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c,objs/%.o,$(SOURCES))

FLAGS = -Wall -Wextra -Werror -O3 -funroll-all-loops
SOFLAGS = -fPIC -shared

NAME = libft.a
DYNN = libft.so

CC = gcc

all: prepare compile

prepare:
	mkdir -p objs

compile: $(NAME) so

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

so: $(OBJECTS)
	$(CC) $(SOFLAGS) -o $(DYNN) $(OBJECTS)

objs/%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)
	rm -rfv objs

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all prepare compile clean fclean re so
