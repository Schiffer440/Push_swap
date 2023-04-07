/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:12:25 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 07:46:53 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*fill_pile(int ac, char **av)
{
	t_pile		*pile_a;
	int			i;
	long int	nb;

	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			printf("wrong number\n");
			return (NULL);
		}
		if (i == 1)
			pile_a = pile_new(nb);
		else
			add_pile_last(&pile_a, pile_new(nb));
		i++;
	}
	return (pile_a);
}

void	pile_index(t_pile *pile_a, int size_pile)
{
	t_pile	*tmp;
	t_pile	*max;
	int		val;

	while (--size_pile > 0)
	{
		tmp = pile_a;
		val = INT_MIN;
		max = NULL;
		while (tmp)
		{
			if (tmp->val == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->val > val && tmp->index == 0)
			{
				val = tmp->val;
				max = tmp;
				tmp = pile_a;
			}
			else
				tmp = tmp->next;
		}
		if (max != NULL)
			max->index = size_pile;
	}
}
