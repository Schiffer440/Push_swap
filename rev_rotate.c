/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:02:17 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 07:55:14 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*last;
	t_pile	*before_last;

	before_last = pile_before_last(*pile);
	last = pile_last(*pile);
	tmp = *pile;
	*pile = last;
	(*pile)->next = tmp;
	before_last->next = NULL;
}

void	rra(t_pile **pile_a)
{
	rev_rotate(pile_a);
	ft_printf("rra\n");
}

void	rrb(t_pile **pile_b)
{
	rev_rotate(pile_b);
	ft_printf("rrb\n");
}

void	rrr(t_pile **pile_a, t_pile **pile_b)
{
	rev_rotate(pile_a);
	rev_rotate(pile_b);
	ft_printf("rrr\n");
}
