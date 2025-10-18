# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/09 01:22:17 by sdeppe            #+#    #+#              #
#    Updated: 2025/10/10 08:12:17 by sdeppe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BASE_NAMES = ft_putchar	\
			ft_putstr	\
			ft_strcmp	\
			ft_strlen	\
			ft_swap

SRC_FILES = $(BASE_NAMES:%=srcs/%.c)

OBJECT_FILES = $(BASE_NAMES:%=srcs/%.o)

HEADER_FILES = $(BASE_NAMES:%=includes/%.h)

CFLAGS += -Wall -Werror -Wextra

CC=gcc

clean:
	rm -f $(OBJECT_FILES)
	
fclean: clean
	rm -f libft.a

all: libft.a
	
re: fclean all

srcs/%.o: srcs/%.c
	$(CC) -c $^ -o $@  $(CFLAGS) 

%.a: $(OBJECT_FILES)
	ar rcs $@ $^
