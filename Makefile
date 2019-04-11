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

FLAGS = -Wall -Wextra -Werror

NAME = libft.a
DYNN = libft.so

all: prepare compile

prepare:
	mkdir -p objs

compile: $(NAME) so

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

so: $(OBJECTS)
	gcc -shared -fPIC -o $(DYNN) $(OBJECTS)

objs/%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)
	rm -rfv objs

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all prepare compile clean fclean re so
