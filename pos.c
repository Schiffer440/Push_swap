/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:23:51 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 07:54:15 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_pos(t_pile **pile)
{
	int		i;
	t_pile	*tmp;

	tmp = *pile;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	get_target(t_pile **pile_a, int index_b, int t_index, int t_pos)
{
	t_pile	*a;

	a = *pile_a;
	while (a)
	{
		if (a->index > index_b && a->index < t_index)
		{
			t_pos = a->pos;
			t_index = a->index;
		}
		a = a->next;
	}
	if (t_index != INT_MAX)
		return (t_pos);
	a = *pile_a;
	while (a)
	{
		if (a->index < t_index)
		{
			t_pos = a->pos;
			t_index = a->index;
		}
		a = a->next;
	}
	return (t_pos);
}

int	get_lowest_index(t_pile **pile)
{
	t_pile	*tmp;
	int		lowest;

	tmp = *pile;
	get_pos(pile);
	while (tmp)
	{
		if (tmp->index == 1)
			lowest = tmp->pos;
		tmp = tmp->next;
	}
	return (lowest);
}

void	get_target_pos(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*b;
	int		target_pos;

	b = *pile_b;
	get_pos(pile_a);
	get_pos(pile_b);
	target_pos = 0;
	while (b)
	{
		target_pos = get_target(pile_a, b->index, INT_MAX, target_pos);
		b->target_pos = target_pos;
		b = b->next;
	}
}
