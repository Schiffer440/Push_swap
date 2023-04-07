# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adugain <adugain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 09:59:59 by adugain           #+#    #+#              #
#    Updated: 2023/03/28 11:49:40 by adugain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

PROG = push_swap

LIBFT = libft/libft.a

SRC = big_sort.c check_val_utils.c check_val.c cost.c \
	format.c ft_printf.c init.c main.c move.c pile.c \
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
