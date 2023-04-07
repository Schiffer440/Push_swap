/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:41:02 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 07:59:15 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_pile **src, t_pile **dest)
{
	t_pile	*tmp;

	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	pa(t_pile **pile_a, t_pile **pile_b)
{
	push(pile_b, pile_a);
	ft_printf("pa\n");
}

void	pb(t_pile **pile_a, t_pile **pile_b)
{
	push(pile_a, pile_b);
	ft_printf("pb\n");
}
