/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:54:39 by adugain           #+#    #+#             */
/*   Updated: 2023/05/03 13:52:00 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	number_check(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

static int	duplicate_check(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && strnb_comp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i])
	{
		if (av[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_int(char *av)
{
	if (atol(av) < INT_MIN || atol(av) > INT_MAX)
		return (0);
	return (1);
}

int	is_valid_input(char **av)
{
	int	i;
	int	zeros;

	i = 1;
	zeros = 0;
	while (av[i])
	{
		if (!number_check(av[i]))
			return (0);
		if (is_valid_int(av[i]) != 1)
			return (0);
		zeros = check_zero(av[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (duplicate_check(av))
		return (0);
	return (1);
}
