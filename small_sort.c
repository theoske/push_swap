/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:38:27 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/06/15 13:52:06 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	three_sized(t_stacks stacks)
{
	int		a;
	int		b;
	int		c;

	a = stacks.stacka->first->nbr;
	b = stacks.stacka->first->next->nbr;
	c = stacks.stacka->first->next->next->nbr;
	if (a > b && b > c)
	{
		stacks = swapa(stacks);
		stacks = rra(stacks);
	}
	else if (a > b && c > b && a < c)
		stacks = swapa(stacks);
	else if (a > b && a > c && c > b)
		stacks.stacka = pre_rotate(stacks.stacka, 0);
	else if (b > a && b > c && c > a)
	{
		stacks = swapa(stacks);
		stacks.stacka = pre_rotate(stacks.stacka, 0);
	}
	else if (b > a && b > c && a > c)
		stacks = rra(stacks);
	return (stacks);
}

t_stacks	four_sized(t_stacks stacks)
{
	stacks = pre_push(stacks, 1);
	stacks = three_sized(stacks);
	stacks = pre_push(stacks, 0);
	if (stacks.stacka->first->nbr > stacks.stacka->first->next->next->next->nbr)
		stacks.stacka = pre_rotate(stacks.stacka, 0);
	else if (stacks.stacka->first->nbr > stacks.stacka->first->next->next->nbr)
	{
		stacks = rra(stacks);
		stacks = swapa(stacks);
		stacks.stacka = pre_rotate(stacks.stacka, 0);
		stacks.stacka = pre_rotate(stacks.stacka, 0);
	}
	else if (stacks.stacka->first->nbr > stacks.stacka->first->next->nbr)
		stacks = swapa(stacks);
	return (stacks);
}

int	find_biggest(t_liste *stack)
{
	t_element	*ptr;
	int			biggest;
	int			placement;

	ptr = stack->first;
	biggest = ptr->nbr;
	while (ptr->next)
	{
		if (ptr->nbr > biggest)
			biggest = ptr->nbr;
		ptr = ptr->next;
	}
	ptr = stack->first;
	placement = 0;
	while (ptr->nbr != biggest)
	{
		ptr = ptr->next;
		placement++;
	}
	return (placement);
}

t_stacks	five_sized_operations(t_stacks stacks)
{
	stacks = pre_push(stacks, 1);
	stacks = three_sized(stacks);
	stacks = pre_push(stacks, 0);
	stacks = pre_push(stacks, 0);
	stacks = swapa(stacks);
	stacks.stacka = pre_rotate(stacks.stacka, 0);
	stacks.stacka = pre_rotate(stacks.stacka, 0);
	return (stacks);
}

t_stacks	five_sized(t_stacks stacks)
{
	int		tab;

	tab = find_biggest(stacks.stacka);
	if (tab == 1)
		stacks = swapa(stacks);
	else if (tab == 2)
	{
		stacks.stacka = pre_rotate(stacks.stacka, 0);
		stacks.stacka = pre_rotate(stacks.stacka, 0);
	}
	else if (tab >= 3)
		stacks = rra(stacks);
	if (tab == 3)
		stacks = rra(stacks);
	stacks = pre_push(stacks, 1);
	tab = find_biggest(stacks.stacka);
	stacks = nameless(stacks, tab);
	return (five_sized_operations(stacks));
}
