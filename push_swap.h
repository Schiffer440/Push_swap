/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:41:48 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 15:26:56 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_pile
{
	int				val;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_pile	*next;
}	t_pile;

int		main(int ac, char **av);
int		ft_printf(const char *str, ...);
int		format(char c, va_list args);
int		is_valid_input(char **av);
int		is_digit(char c);
int		is_sign(char c);
int		strnb_comp(char *s1, char *s2);
t_pile	*fill_pile(int ac, char **av);
int		get_size(t_pile *pile);
void	pile_index(t_pile *pile_a, int size_pile);
int		check_pile(t_pile *pile);
int		ft_atoi(const char *str);
t_pile	*pile_new(int nb);
void	add_pile_last(t_pile **pile, t_pile *new);
t_pile	*pile_last(t_pile *pile);
t_pile	*pile_before_last(t_pile *pile);
void	free_piles(t_pile **pile);
void	sa(t_pile **pile_a);
void	sb(t_pile **pile_b);
void	ss(t_pile **pile_a, t_pile **pile_b);
void	ra(t_pile **pile_a);
void	rb(t_pile **pile_b);
void	rr(t_pile **pile_a, t_pile **pile_b);
void	rra(t_pile **pile_a);
void	rrb(t_pile **pile_b);
void	rrr(t_pile **pile_a, t_pile **pile_b);
void	pa(t_pile **pile_a, t_pile **pile_b);
void	pb(t_pile **pile_a, t_pile **pile_b);
void	small_sort(t_pile **pile);
void	big_sort(t_pile **pile_a, t_pile **pile_b);
void	get_target_pos(t_pile **pile_a, t_pile **pile_b);
void	move_pile(t_pile **pile_a, t_pile **pile_b, int cost_a, int cost_b);
void	get_cost(t_pile **pile_a, t_pile **pile_b);
void	cheapest_move(t_pile **pile_a, t_pile **pile_b);
int		get_lowest_index(t_pile **pile);
int		error(void);

#endif