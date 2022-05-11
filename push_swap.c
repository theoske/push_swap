/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:34:37 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/05/11 16:06:04 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>//

char	*swap(char *tab) // takes stacks a or b
{
	int		swapper;

	if (ft_strlen(tab) <= 1)
		return (tab);
	swapper = tab[0];
	tab[0] = tab[1];
	tab[1] = swapper;
	return (tab);
}

char	**push(char *gifter, char *receiver) //push number 
{
	char	*tab[2];
	int		i;

	if (!gifter)
		return (tab);
	tab[2] = 0;
	tab[0] = malloc(ft_strlen(gifter) - 1);
	tab[1] = malloc(ft_strlen(receiver) + 1);
	tab[1][0] = gifter[0];
	while (receiver && receiver[i])
	{
		tab[1][i + 1] = receiver[i];
		i++;
	}
	tab[1][i + 1] = 0;
	i = 0;
	while (gifter[i + 1])
	{
		tab[0][i] = gifter[i + 1];
		i++;
	}
	tab[0][i] = 0;
	return (tab);
}

char	*rotate(char *str)
{
	int		i;
	char	swapper;
	char	swapper2;
	char	endchar;

	if (!str)
		return (NULL);
	endchar = str[0];
	i = ft_strlen(str) - 1;
	swapper = str[i - 1];
	str[i - 1] = str[i];
	i -= 2;
	swapper2 = str[i];
	str[i] = swapper;
	while (i > 0)
	{
		swapper = str[i - 1];
		str[i - 1] = str[i];
	}
}