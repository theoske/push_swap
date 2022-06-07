/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:34:37 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/06/07 17:56:25 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*argtotab(char **argv)
{
	int		i;
	int		*tab;

	i = 1;
	tab = NULL;
	tab = malloc((ft_strlen(argv) - 1) * 4);
	while (argv[i])
	{
		tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (tab);
}

int	*order(int *value, int argc)
{
	int		i;
	int		j;
	int		*nbr;

	i = 0;
	nbr = malloc(sizeof(int) * argc);
	while (i < argc)
	{
		j = 0;
		nbr[i] = 0;
		while (j < argc)
		{
			if (value[i] > value[j])
				nbr[i]++;
			j++;
		}
		i++;
	}
	return (nbr);
}

t_liste	*valuetoliste(int *value, int argc)
{
	t_liste	*stacka;
	int		i;

	stacka = listinit();
	i = argc - 2;
	while (i >= 0)
		insertlist(stacka, value[i--]);
	return (stacka);
}

int	ft_check(char **argv, int *value)
{
	if (nbr_check(argv) == -1 || dup_check(value) == -1 ||
		lim_check(argv) == -1)
		return (ft_error());
	if (a_sorted(value) == -1)
		return (-1);
	return (0);
}

int main(int argc, char *argv[])
{
	int			*value;
	int			*index;
	t_stacks	stacks;

	value = argtotab(argv);
	if (ft_check(argv, value) == -1)
	{
		free (value);
		return (-1);
	}
	value = order(value, argc - 1);
	stacks.stacka = valuetoliste(value, argc);
	stacks.stackb = listinit();
	stacks = radix_sort(stacks, argc);
	free (value);
	removelist(stacks.stacka);
	removelist(stacks.stackb);
	return (0);
}
