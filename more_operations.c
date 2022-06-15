/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:43:50 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/06/15 13:59:28 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	swapa(t_stacks stacks)
{
	int		swapper;

	swapper = stacks.stacka->first->nbr;
	stacks.stacka->first->nbr = stacks.stacka->first->next->nbr;
	stacks.stacka->first->next->nbr = swapper;
	ft_putstr("sa\n");
	return (stacks);
}

t_stacks	rra(t_stacks stacks)
{
	t_element	*last;
	t_element	*ptr;

	last = stacks.stacka->first;
	while (last->next->next)
		last = last->next;
	ptr = stacks.stacka->first;
	while (ptr->next->next->next)
		ptr = ptr->next;
	ptr->next = ptr->next->next;
	last->next = stacks.stacka->first;
	stacks.stacka->first = last;
	ft_putstr("rra\n");
	return (stacks);
}

t_stacks	nameless(t_stacks stacks, int tab)
{
	if (tab == 1)
		stacks = swapa(stacks);
	else if (tab == 2)
	{
		stacks.stacka = pre_rotate(stacks.stacka, 0);
		stacks.stacka = pre_rotate(stacks.stacka, 0);
	}
	else if (tab >= 3)
		stacks = rra(stacks);
	return (stacks);
}
