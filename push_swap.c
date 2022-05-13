/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:34:37 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/05/12 18:33:23 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


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

/* 
0 : sa
1 : sb
2 : ss

*/

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

/* 0 : sa
1 : sb
2 : ss
*/
char	*swap(char *tab, int doprint)
{
	int		swapper;

	if (ft_strlen(tab) <= 1)
		return (tab);
	swapper = tab[0];
	tab[0] = tab[1];
	tab[1] = swapper;
	if (doprint == 0)
		ft_putstr("sa");
	if (doprint == 1)
		ft_putstr("sb");
	return (tab);
}

char	**push(char *gifter, char *receiver)
{
	char	**tab;
	int		i;

	if (!gifter)
		return (NULL);
	tab = malloc(2);
	tab[0] = malloc(ft_strlen(gifter) - 1);
	tab[1] = malloc(ft_strlen(receiver) + 1);
	tab[1][0] = gifter[0];
	i = 0;
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
	swapper = str[i];
	while (i > 0)
	{
		swapper2 = str[i];
		str[i] = swapper;
		i--;
		swapper = str[i];
		str[i] = swapper2;
		i--;
	}
	str[ft_strlen(str) - 1] = endchar;
	return (str);
}

char	*rev_rotate(char *str)
{
	int		i;
	char	swapper;
	char	swapper2;
	char	startchar;

	if (!str)
		return (NULL);
	startchar = str[ft_strlen(str) - 1];
	i = 0;
	swapper = str[i];
	while (str[i + 1])
	{
		swapper2 = str[i];
		str[i] = swapper;
		i++;
		swapper = str[i];
		str[i] = swapper2;
		i++;
	}
	str[0] = startchar;
	return (str);
}

char	**double_swap(char **tab)
{
	tab[0] = swap(tab[0], 2);
	tab[1] = swap(tab[1], 2);
	ft_putstr("ss\n");
	return (tab);
}

// 0 a_push
// 1 b_push
char	**pre_push(char *giver, char *receiver, int nb)
{
	char	**tab;

	tab = push(giver, receiver);
	if (nb == 0)
		ft_putstr("pa\n");
	else if (nb == 1)
		ft_putstr("pb\n");
	return (tab);
}

int main()
{
	char str[] = "12345";
	char str2[] = "789";
	char **tab;
	tab = malloc(2);
	// tab[0] = str;
	// tab[1] = str2;
	tab = pre_push(str, str2, 0);
	// printf(" %s ", tab[0]);
	return (0);
}
