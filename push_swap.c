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
int	*swap(int *tab, int option)
{
	int		swapper;

	if ((sizeof(tab) / 4) <= 1)
		return (tab);
	swapper = tab[0];
	tab[0] = tab[1];
	tab[1] = swapper;
	if (option == 0)
		ft_putstr("sa");
	if (option == 1)
		ft_putstr("sb");
	return (tab);
}

int	**push(int *gifter, int *receiver)
{
	int		**tab;
	int		i;

	if (sizeof(gifter) == 0)
		return (NULL);
	tab = malloc(4);
	tab[0] = malloc(sizeof(gifter) - 4);
	tab[1] = malloc(sizeof(receiver) + 4);
	tab[1][0] = gifter[0];
	i = 0;
	while ((sizeof(receiver) - 4) > (i * 4))
	{
		tab[1][i + 1] = receiver[i];
		i++;
	}
	i = 0;
	while ((i * 4) < (sizeof(gifter) + 4))
	{
		tab[0][i] = gifter[i + 1];
		i++;
	}
	return (tab);
}

int	*rotate(int *str)
{
	int		i;
	int		swapper;
	int		swapper2;
	int		endchar;

	if (sizeof(str) == 0)
		return (NULL);
	endchar = str[0];
	i = (sizeof(str) / 4);
	swapper = str[i];
	while (i >= 0)
	{
		swapper2 = str[i];
		str[i] = swapper;
		i--;
		if (i >= 0)
		{
			swapper = str[i];
			str[i] = swapper2;
			i--;
		}
	}
	str[sizeof(str) / 4] = endchar;
	return (str);
}

int	*rev_rotate(int *str)
{
	int		i;
	int		swapper;
	int		swapper2;
	int		startchar;

	if (sizeof(str) == 0)
		return (NULL);
	startchar = str[sizeof(str) / 4];
	i = 0;
	swapper = str[i];
	while ((i * 4) <= sizeof(str))
	{
		swapper2 = str[i];
		str[i] = swapper;
		i++;
		if ((i * 4) <= sizeof(str))
		{
			swapper = str[i];
			str[i] = swapper2;
			i++;
		}
	}
	str[0] = startchar;
	return (str);
}

int	**double_swap(int **tab)
{
	tab[0] = swap(tab[0], 2);
	tab[1] = swap(tab[1], 2);
	ft_putstr("ss\n");
	return (tab);
}

// 0 a_push
// 1 b_push
int	**pre_push(int *giver, int *receiver, int nb)
{
	int		**tab;

	tab = push(giver, receiver);
	if (nb == 0)
		ft_putstr("pa\n");
	else if (nb == 1)
		ft_putstr("pb\n");
	return (tab);
}

/* 0 ra
 1 rb
 2 rr
*/
int	**pre_rotate(int **tab, int option)
{
	if (option == 0)
	{
		tab[0] = rotate(tab[0]);
		ft_putstr("ra\n");
	}
	else if (option == 1)
	{
		tab[1] = rotate(tab[1]);
		ft_putstr("rb\n");
	}
	else if (option == 2)
	{
		tab[0] = rotate(tab[0]);
		tab[1] = rotate(tab[1]);
		ft_putstr("rr\n");
	}
	return (tab);
}

/* 0 rra
 1 rrb
 2 rrr
*/
int	**pre_rev_rotate(int **tab, int option)
{
	if (option == 0)
	{
		tab[0] = rev_rotate(tab[0]);
		ft_putstr("rra\n");
	}
	else if (option == 1)
	{
		tab[1] = rev_rotate(tab[1]);
		ft_putstr("rrb\n");
	}
	else if (option == 2)
	{
		tab[0] = rev_rotate(tab[0]);
		tab[1] = rev_rotate(tab[1]);
		ft_putstr("rrr\n");
	}
	return (tab);
}

int	ft_finder(const char *nptr)
{
	int		i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			j;
	int			neg;
	long int	nb;

	neg = 1;
	i = ft_finder(nptr);
	nb = 0;
	if (nptr[i] == '-' && nptr[i - 1] != '+')
	{
		neg = -1;
		i++;
	}
	j = i;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb *= 10;
		nb += (nptr[i] - 48);
		i++;
	}
	if (i - j > 10 && neg == 1)
		return (-1);
	if (i - j > 10)
		return (0);
	return (nb * neg);
}

int	ft_intlen(int *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*ft_strjoin(int *s1, int *s2)
{
	int		*join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	join = malloc(sizeof(int) * (sizeof(s1) + sizeof(s2) + 1));
	if (!join)
		return (NULL);
	while (s1 && s1[i])
	{
		join[i] = *(char *)(s1 + i);
		i++;
	}
	while (s2[j])
	{
		join[i + j] = *(char *)(s2 + j);
		j++;
	}
	free (s1);
	return (join);
}

int	*argtotab(char **argv)// probleme avec dernier nbr
{
	int		i;
	int		*tab;
	int		*tab2;

	i = 1;
	tab = NULL;
	while (argv[i])
	{
		tab2 = tab;
		tab = malloc(sizeof(tab) + 4);
		tab[i - 1] = ft_atoi(argv[i]);
		tab = ft_strjoin(tab2, tab + i - 1);
		i++;
	}
	return (tab);
}

int	a_sorted(int *value)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (value[i + 1])
	{
		if (value[i] > value[i + 1])
			return (0);
		i++;
	}
	return (-1);
}

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

int	lim_check(int *value)
{
	int		i;

	i = 0;
	while (value[i])
	{
		if (value[i] > 2147483647 || value[i] < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check(char **argv, int *value)
{
	if (nbr_check(argv) == -1)
		return (-1);
	if (lim_check(value) == -1)
		return (-1);
	if (a_sorted(value) == -1)
		return (-1);
	if (dup_check(value) == -1)
		return (-1);
	return (0);
}

int	ft_error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

int	*order(int *stacka)
{
	int		i;
	int		j;
	int		*nbr;

	i = 0;
	nbr = malloc(sizeof(stacka));
	while (stacka[i])
	{
		j = 0;
		nbr[i] = 0;
		while (stacka[j])
		{
			if (stacka[i] > stacka[j])
				nbr[i]++;
			j++;
		}
		i++;
	}
	return (nbr);
}

int	ft_bigbit(int *stack)
{
	int		i;

	i = 0;
	
}

void	radix_sort(int *value)
{
	int		i;
	int		j;
	int		*stack[2];
	int		**ret;
	int		bitpush;

	stack[0] = order(value);
	stack[1] = malloc(sizeof(stack[0]));
	bitpush = 0;
	while (bitpush <= ft_bigbit(stack[0]))// trier de lunite a la centaine
	{
		i = 0;
		while (i < (sizeof(value) / 4))// trie 1 bit
		{
			if ((stack[0][i] >> bitpush % 2) == 0)
				ret = pre_push(stack[0], stack[1], 1);
			else
				ret = pre_rotate(stack, 0);
			i++;
		}
		j = 0;
		while (ret[1][j])// remet dans stacka
		{
			ret = pre_push(ret[1], ret[0], 0);
			j++;
		}
	}
}

int main(int argc, char **argv)
{
	// int		*value;
	// int		*index;

	// value = argtotab(argv);
	// if (ft_check(argv, value) == -1)
	// {
	// 	free (value);
	// 	return (ft_error());
	// }

	int str[] = {1, 2, 3};
	int str2[] = {4};
	int **tab;
	tab = malloc(2);
	tab[0] = str;
	tab[1] = str2;
	tab = pre_rev_rotate(tab, 0);
	printf("%d\n", tab[0][1]);
	printf("%d\n", tab[0][2]);

	// if (argc < 5)
	// 	printf("argc < 5\n");//small_sort(value);//a faire
	// else
	// 	radix_sort(value);//a faire
	// free (value);
	return (0);
}

// int i = 0;
// 	while (argv[i + 1])
// 	{
// 		printf("%d", value[i]);
// 		i++;
// 	}

// char str[] = "12345";
// char str2[] = "789";
// char **tab;
// tab = malloc(2);
// tab[0] = str;
// tab[1] = str2;
// tab = pre_rev_rotate(tab, 2);
// printf("%s\n", tab[0]);
// printf("%s\n", tab[1]);