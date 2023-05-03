/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:18:16 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 07:57:55 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_rrr(t_pile **pile_a, t_pile **pile_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(pile_a, pile_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	move_rr(t_pile **pile_a, t_pile **pile_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(pile_a, pile_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	ra_or_rra(t_pile **pile_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a < 0)
		{	
			rra(pile_a);
			(*cost_a)++;
		}
		else if (*cost_a > 0)
		{	
			ra(pile_a);
			(*cost_a)--;
		}
	}
}

static void	rb_or_rrb(t_pile **pile_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b < 0)
		{
			rrb(pile_b);
			(*cost_b)++;
		}	
		else if (*cost_b > 0)
		{	
			rb(pile_b);
			(*cost_b)--;
		}
	}
}

void	move_pile(t_pile **pile_a, t_pile **pile_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		move_rrr(pile_a, pile_b, &cost_a, &cost_b);
	if (cost_a > 0 && cost_b > 0)
		move_rr(pile_a, pile_b, &cost_a, &cost_b);
	ra_or_rra(pile_a, &cost_a);
	rb_or_rrb(pile_b, &cost_b);
	pa(pile_a, pile_b);
}
