/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:50:39 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 08:30:54 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_pile **pile_a, t_pile **pile_b, int size_pile)
{
	if (size_pile == 2 && !check_pile(*pile_a))
		sa(pile_a);
	else if (size_pile == 3)
		small_sort(pile_a);
	else if (size_pile > 3 && !check_pile(*pile_a))
		big_sort(pile_a, pile_b);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		size_pile;

	if (ac == 1)
		return (0);
	if (is_valid_input(av) != 1)
		return ((int)error());
	pile_b = NULL;
	pile_a = fill_pile(ac, av);
	size_pile = get_size(pile_a);
	pile_index(pile_a, size_pile + 1);
	push_swap(&pile_a, &pile_b, size_pile);
	free_piles(&pile_a);
	free_piles(&pile_b);
	return (0);
}
