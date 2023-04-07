/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:03:09 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 07:57:00 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_pile *pile)
{
	int	tmp_val;
	int	tmp_index;

	tmp_val = pile->val;
	tmp_index = pile->index;
	pile->val = pile->next->val;
	pile->index = pile->next->index;
	pile->next->val = tmp_val;
	pile->next->index = tmp_index;
}

void	sa(t_pile **pile_a)
{
	swap(*pile_a);
	ft_printf("sa\n");
}

void	sb(t_pile **pile_b)
{
	swap(*pile_b);
	ft_printf("sb\n");
}

void	ss(t_pile **pile_a, t_pile **pile_b)
{
	swap(*pile_a);
	swap(*pile_b);
	ft_printf("ss\n");
}
