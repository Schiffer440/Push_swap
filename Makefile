# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adugain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 09:59:59 by adugain           #+#    #+#              #
#    Updated: 2023/04/08 14:21:08 by adugain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

PROG = push_swap

LIBFT = libft/libft.a

SRC =	valid_input_utils.c is_valid_input.c cost.c \
	init.c main.c move_pile.c pile.c big_sort.c \
	pos.c push.c rev_rotate.c rotate.c small_sort.c swap.c utils.c

CFLAGS	= -Wextra -Wall -Werror

OBJ = $(SRC:.c=.o)

$(NAME): 
	gcc -o $(PROG) $(CFLAGS) $(SRC) $(LIBFT)
	gcc -c $(SRC)
	ar -rcs $(NAME) $(OBJ)
	make clean

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f *.a

re: fclean all

.PHONY: all clean fclean re
