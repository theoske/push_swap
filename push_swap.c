/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:34:37 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/08/09 19:14:37 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*argtotab(char **argv, int argc)
{
	int		i;
	int		*tab;

	i = 1;
	tab = NULL;
	tab = malloc((argc - 1) * sizeof(int));
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
	nbr = malloc(sizeof(int) * (argc - 1));
	while (i < argc - 1)
	{
		j = 0;
		nbr[i] = 0;
		while (j < argc - 1)
		{
			if (value[i] > value[j])
				nbr[i]++;
			j++;
		}
		i++;
	}
	free (value);
	return (nbr);
}

t_liste	*valuetoliste(int *value, int argc)
{
	t_liste	*stacka;
	int		i;

	stacka = listinit();
	i = argc - 2;
	while (i >= 0)
	{
		insertlist(stacka, value[i]);
		i--;
	}
	return (stacka);
}

t_stacks	small_sort(t_stacks stacks, int argc)
{
	if (argc == 3)
		return (swapa(stacks));
	else if (argc == 4)
		return (three_sized(stacks));
	else if (argc == 5)
		return (four_sized(stacks));
	else
		return (five_sized(stacks));
}

int	main(int argc, char *argv[])
{
	int			*value;
	t_stacks	stacks;

	if (argc == 2)
		value = one_arg(argv, &argc);
	else
		value = argtotab(argv, argc);
	if (ft_check(argv, value, argc) == -1)
	{
		free (value);
		return (-1);
	}
	value = order(value, argc);
	stacks.stacka = valuetoliste(value, argc);
	stacks.stackb = listinit();
	if (argc > 6)
		stacks = radix_sort(stacks, argc);
	else
		stacks = small_sort(stacks, argc);
	removelist(stacks.stacka);
	removelist(stacks.stackb);
	free (value);
	return (0);
}
