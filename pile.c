/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:29:26 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 07:56:31 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pile_new(int nb)
{
	t_pile	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->val = nb;
	new->index = 0;
	new->pos = 0;
	new->target_pos = 0;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	add_pile_last(t_pile **pile, t_pile *new)
{
	t_pile	*tail;

	if (!new)
		return ;
	if (!*pile)
	{
		*pile = new;
		return ;
	}	
	tail = pile_last(*pile);
	tail->next = new;
}

t_pile	*pile_last(t_pile *pile)
{
	while (pile && pile->next != NULL)
		pile = pile->next;
	return (pile);
}

t_pile	*pile_before_last(t_pile *pile)
{
	while (pile && pile->next && pile->next->next != NULL)
		pile = pile->next;
	return (pile);
}

int	get_size(t_pile *pile)
{
	int	size;

	size = 0;
	if (!pile)
		return (0);
	while (pile)
	{
		pile = pile->next;
		size++;
	}
	return (size);
}
