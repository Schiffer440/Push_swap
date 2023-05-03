# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adugain <adugain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 09:59:59 by adugain           #+#    #+#              #
#    Updated: 2023/05/03 14:40:13 by adugain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

PROG = push_swap

LIBFT = libft/libft.a

SRC = big_sort.c is_valid_input.c cost.c \
	fill_index.c main.c move.c pile.c \
	pos.c push.c rev_rotate.c rotate.c small_sort.c swap.c utils.c

CFLAGS	= -Wextra -Wall -Werror

OBJ = $(SRC:.c=.o)

$(NAME):
	make -C libft
	gcc -o $(PROG) $(CFLAGS) $(SRC) $(LIBFT)
	gcc -c $(SRC)
	ar -rcs $(NAME) $(OBJ)
	make clean

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f *.a
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
