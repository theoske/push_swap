/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arguments_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:44:43 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/06/07 17:56:30 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_check(int *value)
{
	int		i;
	int		j;

	i = 0;
	while (value[i])
	{
		j = 0;
		while (value[j])
		{
			if (i != j && value[i] == value[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	nbr_check(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] > '9' || argv[i][j] < '0')
			&& argv[i][0] != '-' || (argv[i][0] == '-'
			&& argv[i][1] == 0))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	neglim_check(char *str)
{
	if (ft_strlen(str) > 11 || (ft_strlen(str) == 11 &&
		ft_strncmp(str, "-2147483648", 11) > 0))
		return (-1);	
	return (0);
}

int	poslim_check(char *str)
{
	if (ft_strlen(str) > 10 || (ft_strlen(str) == 10 &&
		ft_strncmp(str, "2147483647", 10) > 0))
		return (-1);	
	return (0);
}

int	lim_check(char **argv)
{
	int		i;
	int		ret;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-')
			ret = neglim_check(argv[i]);
		else
			ret = poslim_check(argv[i]);
		if (ret == -1)
			return(-1);
		i++;
	}
	return (0);
}
