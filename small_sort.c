/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:32:36 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 07:55:45 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest_index(t_pile *pile)
{
	int	index;

	index = pile->index;
	while (pile)
	{
		if (pile->index > index)
			index = pile->index;
		pile = pile->next;
	}
	return (index);
}

void	small_sort(t_pile **pile)
{
	int	highest;

	highest = get_highest_index(*pile);
	if (check_pile(*pile) == 1)
		return ;
	if ((*pile)->index == highest)
		ra(pile);
	else if ((*pile)->next->index == highest)
		rra(pile);
	if ((*pile)->index > (*pile)->next->index)
		sa(pile);
}
