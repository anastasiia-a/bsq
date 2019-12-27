#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmeribal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/15 10:19:13 by tmeribal          #+#    #+#              #
#    Updated: 2019/08/21 17:38:04 by tmeribal         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bsq
 
SRC = main.c

SRC_LIB = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_atoi.c srcs/ft_strlen.c srcs/bsq.c srcs/ft_strcpy.c srcs/readtext.c

NAME_LIB = ftlib.a

HEADER_DIR = srcs/includes

KEYS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(KEYS) $(SRC_LIB)
	ar rc $(NAME_LIB) ft_putchar.o ft_putstr.o ft_atoi.o ft_strlen.o bsq.o ft_strcpy.o readtext.o
	ranlib $(NAME_LIB)
	gcc $(KEYS) -o $(NAME) $(SRC) -I$(HEADER_DIR) $(NAME_LIB)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME_LIB) $(NAME)

re: fclean all
