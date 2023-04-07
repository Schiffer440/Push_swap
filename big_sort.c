/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:39:37 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 07:58:58 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_in_a(t_pile **pile_a, t_pile **pile_b)
{
	int	size_pile;
	int	push;
	int	i;

	i = 0;
	push = 0;
	size_pile = get_size(*pile_a);
	while (size_pile > 6 && i < size_pile && push < size_pile / 2)
	{
		if ((*pile_a)->index <= size_pile / 2)
		{	
			pb(pile_a, pile_b);
			push++;
		}
		else
			ra(pile_a);
		i++;
	}
	while (size_pile - push > 3)
	{
		pb(pile_a, pile_b);
		push++;
	}
}

static void	right_rotate(t_pile **pile_a)
{
	int	lowest_index;
	int	size_a;

	lowest_index = get_lowest_index(pile_a);
	size_a = get_size(*pile_a);
	if (lowest_index >= size_a / 2)
	{
		while (lowest_index < size_a)
		{
			rra(pile_a);
			lowest_index++;
		}
	}
	else
	{	
		while (lowest_index > 0)
		{
			ra(pile_a);
			lowest_index--;
		}
	}
}

void	big_sort(t_pile **pile_a, t_pile **pile_b)
{
	three_in_a(pile_a, pile_b);
	small_sort(pile_a);
	while (*pile_b)
	{
		get_target_pos(pile_a, pile_b);
		get_cost(pile_a, pile_b);
		cheapest_move(pile_a, pile_b);
	}
	if (!check_pile(*pile_a))
		right_rotate(pile_a);
}
