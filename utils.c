/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:08:08 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 08:00:52 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	sign = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		sign = -sign;
		i++;
	}
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

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
