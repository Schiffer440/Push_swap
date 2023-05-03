/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:08:08 by adugain           #+#    #+#             */
/*   Updated: 2023/05/03 15:16:24 by adugain          ###   ########.fr       */
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

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}
