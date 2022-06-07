/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:40:23 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/06/07 17:56:32 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*rotate(t_liste *stack)
{
	int			nbr1;
	t_element	*ptr;

	nbr1 = stack->first->nbr;
	ptr = stack->first;
	while (ptr->next->next)
	{
		ptr->nbr = ptr->next->nbr;
		ptr = ptr->next;
	}
	ptr->nbr = nbr1;
	return (stack);
}

t_stacks	pushb(t_stacks stacks)
{
	insertlist(stacks.stackb, unpile(stacks.stacka));
	return (stacks);
}

t_stacks	pusha(t_stacks stacks)
{
	insertlist(stacks.stacka, unpile(stacks.stackb));
	return (stacks);
}

t_stacks	pre_push(t_stacks stacks, int nb)
{
	if (nb == 0)
	{
		stacks = pusha(stacks);
		ft_putstr("pa\n");
	}
	else
	{
		stacks = pushb(stacks);
		ft_putstr("pb\n");
	}
	return (stacks);
}

t_liste	*pre_rotate(t_liste *stack, int option)
{
	if (option == 0)
	{
		stack = rotate(stack);
		ft_putstr("ra\n");
	}
	else if (option == 1)
	{
		stack = rotate(stack);
		ft_putstr("rb\n");
	}
	return (stack);
}