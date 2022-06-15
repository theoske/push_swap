/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:51:33 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/06/15 14:03:32 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_liste *stacka)
{
	int			i;
	int			j;
	t_element	*ptr;

	ptr = stacka->first;
	while (ptr->next->next)
	{
		i = ptr->nbr;
		j = ptr->next->nbr;
		if (i > j)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	ft_bigbit(int *stack)
{
	unsigned long int	i;
	int					j;
	int					ret;

	i = 0;
	j = 0;
	while (i < (sizeof(stack) / 4))
	{
		if (stack[i] > j)
			j = stack[i];
		i++;
	}
	ret = 1;
	while (j > 0)
	{
		j /= 2;
		ret++;
	}
	return (ret);
}

t_stacks	radix_sort(t_stacks stacks, int argc)
{
	int		i;
	int		j;
	int		nbr;

	i = 0;
	while (stack_sorted(stacks.stacka) == 0)
	{
		j = 0;
		while (++j < argc)
		{
			nbr = stacks.stacka->first->nbr;
			if (((nbr >> i) & 1) == 1)
				stacks.stacka = pre_rotate(stacks.stacka, 0);
			else
				stacks = pre_push(stacks, 1);
		}
		while (stacks.stackb->first->next)
			stacks = pre_push(stacks, 0);
		i++;
	}
	return (stacks);
}

int	a_sorted(int *value, int argc)
{
	int		i;

	i = 0;
	while ((i + 2) < argc)
	{
		if (value[i] > value[i + 1])
			return (0);
		i++;
	}
	write(1, "\n", 1);
	return (-1);
}
