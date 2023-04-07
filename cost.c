/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:14:40 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 07:48:09 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*a;
	t_pile	*b;
	int		size_a;
	int		size_b;

	a = *pile_a;
	b = *pile_b;
	size_a = get_size(a);
	size_b = get_size(b);
	while (b)
	{
		b->cost_b = b->pos;
		if (b->pos > size_b / 2)
			b->cost_b = (size_b - b->pos) * -1;
		b->cost_a = b->target_pos;
		if (b->target_pos > size_a / 2)
			b->cost_a = (size_a - b->target_pos) * -1;
		b = b->next;
	}
}

void	cheapest_move(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	int		cost_a;
	int		cost_b;
	int		cheapest;

	cheapest = INT_MAX;
	tmp = *pile_b;
	while (tmp)
	{
		if (abs(tmp->cost_a) + abs(tmp->cost_b) < cheapest)
		{
			cheapest = abs(tmp->cost_a) + abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move_pile(pile_a, pile_b, cost_a, cost_b);
}
