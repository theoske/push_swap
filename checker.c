/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:42:02 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/08/09 17:37:19 by tkempf-e         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = *(char *)(s1 + i);
		i++;
	}
	while (s2[j])
	{
		join[i + j] = *(char *)(s2 + j);
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

int	ft_check(char **argv, int *value, int argc)
{
	char	**newargv;

	newargv = argv;
	if (argc > 2 && !argv[2])
		newargv = ft_split(ft_strjoin(ft_strjoin(argv[0], " "), argv[1]), ' ');
	if (nbr_check(newargv) == -1 || dup_check(value, argc) == -1
		|| lim_check(newargv) == -1)
	{
		freenewargv(&newargv);
		return (ft_error());
	}
	if (a_sorted(value, argc) == -1)
	{
		freenewargv(&newargv);
		return (-1);
	}
	freenewargv(&newargv);
	return (0);
}
