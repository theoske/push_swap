/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:34:37 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/05/10 17:50:48 by tkempf-e         ###   ########.fr       */
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