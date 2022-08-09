/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:34:31 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/08/09 18:56:02 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!str1[i] && !str2[i]) || n == 0)
		return (0);
	n--;
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < n)
		i++;
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}

int	ft_error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

void	freenewargv(char ***newargvptr)
{
	int		i;
	char	**newargv;

	i = 0;
	newargv = *newargvptr;
	while (newargv && newargv[i])
		i++;
	i--;
	while (i >= 0)
	{
		free (newargv[i]);
		i--;
	}
	free (newargv);
}
