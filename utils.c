/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:08:08 by adugain           #+#    #+#             */
/*   Updated: 2023/04/07 15:21:16 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_piles(t_pile **pile)
{
	t_pile	*tmp;

	if (!pile || !*pile)
		return ;
	while (*pile)
	{
		tmp = (*pile)->next;
		free(*pile);
		*pile = tmp;
	}
}

int	check_pile(t_pile *pile)
{
	while (pile->next != NULL)
	{
		if (pile->index > pile->next->index)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int	abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}
