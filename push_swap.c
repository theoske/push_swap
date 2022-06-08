/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:34:37 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/06/08 17:04:49 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*argtotab(char **argv, int argc)
{
	int		i;
	int		*tab;

	i = 1;
	tab = NULL;
	tab = malloc((argc - 2) * sizeof(int));
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

t_stacks	swapa(t_stacks stacks)
{
	int		swapper;

	swapper = stacks.stacka->first->nbr;
	stacks.stacka->first->nbr = stacks.stacka->first->next->nbr;
	stacks.stacka->first->next->nbr = swapper;
	ft_putstr("sa\n");
	return (stacks);
}

t_stacks	rra(t_stacks stacks)//dernier passe premier   insertlist(stacks, last)
{
	int			last;
	int			swapper;
	t_element	*ptr;

	ptr = stacks.stacka->first;
	while (ptr->next)
	{
		last = ptr->nbr;
		ptr = ptr->next;
	}
	insertlist(stacks.stacka, last);
	ptr = stacks.stacka->first;
	while (ptr->next->next)
		ptr = ptr->next;
	free (ptr->next);
	ptr = 0;
	return (stacks);
}

t_stacks	three_sized(t_stacks stacks)//123   321   213   312   132  231
{
	int		a;
	int		b;
	int		c;

	a = stacks.stacka->first->nbr;
	b = stacks.stacka->first->next->nbr;
	c = stacks.stacka->first->next->next->nbr;
	if (a > b && b > c)// 321
	{
		stacks = swapa(stacks);
		stacks.stacka = pre_rotate(stacks.stacka, 0);
		stacks.stacka = pre_rotate(stacks.stacka, 0);
	}
	else if (a > b && c > b && a < c)//213
		stacks = swapa(stacks);
	else if (a > b && a > c && c > b)//312
		stacks.stacka = pre_rotate(stacks.stacka, 0);
	else if (b > a && b > c && c > a)//132
	{
		stacks = swapa(stacks);
		stacks.stacka = pre_rotate(stacks.stacka, 0);
	}
	else if (b > a && b > c && a > c)//231
		stacks = rra(stacks);
	return (stacks);
}

t_stacks	four_sized(t_stacks stacks)//1234  2134    3124    4123
{
	stacks = pre_push(stacks, 1);
	stacks = three_sized(stacks);
	stacks = pre_push(stacks, 0);
	if (stacks.stacka->first->nbr > stacks.stacka->first->next->next->next->nbr)//4123
		stacks.stacka = pre_rotate(stacks.stacka, 0);
	else if (stacks.stacka->first->nbr > stacks.stacka->first->next->next->nbr)//3124 
	{
		stacks = rra(stacks);
		stacks = swapa(stacks);
		stacks = rra(stacks);
		stacks = rra(stacks);
	}
	else if (stacks.stacka->first->nbr > stacks.stacka->first->next->nbr)//2134
		stacks = swapa(stacks);
	return (stacks);
}
//mettre nbrs en trop dans b et trier a la main
t_stacks	five_sized(t_stacks stacks)//21345  31245 41235  51234
{
	t_element	*ptr;
	int			smallest;
	int			biggest;

	ptr = stacks.stacka->first;
	smallest = ptr->nbr;
	biggest = ptr->nbr;
	while (ptr->next->next)//trouve valeur plus petit nbr et plus grand
	{
		if (ptr->nbr > biggest)
			biggest = ptr->nbr;
		if (ptr->nbr < smallest)
			smallest = ptr->nbr;
		ptr = ptr->next;
	}
	//mettre +petit et +grand dans stackb (les retrouver par concordance)

	stacks = pre_push(stacks, 1);
	stacks = pre_push(stacks, 1);


	if (newstacks.stacka->first->nbr > newstacks.stacka->first->next->next->next->next->nbr)//51234
		newstacks.stacka = pre_rotate(newstacks.stacka, 0);
	else if (newstacks.stacka->first->nbr > newstacks.stacka->first->next->next->next->nbr)//41235
	{
		newstacks = rra(newstacks);
		newstacks = swapa(newstacks);
		newstacks.stacka = pre_rotate(newstacks.stacka, 0);
		newstacks.stacka = pre_rotate(newstacks.stacka, 0);
	}
	else if (newstacks.stacka->first->nbr > newstacks.stacka->first->next->next->nbr)//31245   pb213  rb321  pa12345
	{

	}
}

t_stacks	small_sort(t_stacks stacks, int argc)//mettre nbrs en trop dans b et trier a la main
{
	if (argc == 3)
		return (swapa(stacks));
	else if (argc == 4)
		return (three_sized(stacks));
	else if (argc == 5)
		return (four_sized(stacks));
	else if (argc == 6)
		return (five_sized(stacks));
}

int main(int argc, char *argv[])
{
	int			*value;
	t_stacks	stacks;

	value = argtotab(argv, argc);
	if (ft_check(argv, value) == -1)
	{
		free (value);
		return (-1);
	}
	value = order(value, argc - 1);
	stacks.stacka = valuetoliste(value, argc);
	stacks.stackb = listinit();
	if (argc > 6)
		stacks = radix_sort(stacks, argc);
	else
		stacks = small_sort(stacks, argc);
	free (value);
	removelist(stacks.stacka);
	removelist(stacks.stackb);
	return (0);
}
