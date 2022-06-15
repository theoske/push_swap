/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:42:02 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/06/15 13:59:11 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_check(int *value, int argc)
{
	int		i;
	int		j;

	i = 0;
	while (i < (argc - 1))
	{
		j = 0;
		while (j < argc - 1)
		{
			if (j != i && value[i] == value[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check(char **argv, int *value, int argc)
{
	if (nbr_check(argv) == -1 || dup_check(value, argc) == -1
		|| lim_check(argv) == -1)
		return (ft_error());
	if (a_sorted(value, argc) == -1)
		return (-1);
	return (0);
}
