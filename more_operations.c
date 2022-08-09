/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:43:50 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/08/09 18:57:40 by tkempf-e         ###   ########.fr       */
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

int	*one_argtotab(char **argv, int argc)
{
	int		i;
	int		*tab;

	i = 0;
	tab = NULL;
	tab = malloc((argc - 1) * sizeof(int));
	while (argv[i])
	{
		tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (tab);
}

int	*one_arg(char **argv, int *argcptr)
{
	char	**newargv;
	int		*value;
	int		i;

	newargv = ft_split(ft_strjoin(ft_strjoin(argv[0], " "), argv[1]), ' ');
	i = 0;
	while (newargv && newargv[i])
		i++;
	*argcptr = i;
	value = one_argtotab(newargv, i);
	freenewargv(&newargv);
	return (value);
}
