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

typedef struct s_element	t_element;
struct s_element
{
	int			nbr;
	t_element	*next;
};

//structure de controle contenant le premier element de la liste
typedef struct s_liste
{
	t_element	*first;
}	t_liste;

t_liste	*listinit(void)
{
	t_liste		*liste;
	t_element	*element;

	element = malloc(sizeof(*element));
	liste = malloc(sizeof(*liste));
	if (!liste || !element)
		exit(EXIT_FAILURE);
	element->nbr = 0;
	element->next = NULL;
	liste->first = element;
	return (liste);
}

// empile un nouvel element a la liste
void	insertlist(t_liste *liste, int newnbr)
{
	t_element	*new;

	new = malloc(sizeof(*new));
	if (!liste || !new)
		exit(EXIT_FAILURE);
	new->nbr = newnbr;
	new->next = liste->first;
	liste->first = new;
}

void	removelist(t_liste *liste)
{
	t_element	*todelete;

	if (!liste)
		exit(EXIT_FAILURE);
	if (liste->first != NULL)
	{
		todelete = liste->first;
		liste->first = liste->first->next;
		free (todelete);
	}
}

int	unpile(t_liste *liste)
{
	int			pilenbr;
	t_element	*pileelement;

	if (!liste)
		exit(EXIT_FAILURE);
	pilenbr = 0;
	pileelement = liste->first;
	if (liste != NULL && liste->first != NULL)
	{
		pilenbr = pileelement->nbr;
		liste->first = pileelement->next;
		free (pileelement);
	}
	return (pilenbr);
}

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
		ft_putstr("sa\n");
	if (option == 1)
		ft_putstr("sb\n");
	return (tab);
}

t_liste	*rotate(t_liste *stack)
{
	int			nbr1;
	t_element	*ptr;

	nbr1 = stack->first->nbr;
	ptr = stack->first;
	while (ptr->next->next->next)
	{
		ptr->nbr = ptr->next->nbr;
		ptr = ptr->next;
	}
	ptr->nbr = nbr1;
	return (stack);
}

// 0 a_push
// 1 b_push
// int	**pre_push(int *giver, int *receiver, int nb)
// {
// 	int		**tab;

// 	if (nb == 0)
// 	{
// 		tab = pusha(giver, receiver);
// 		ft_putstr("pa\n");
// 	}
// 	else
// 	{
// 		tab = pushb(giver, receiver);
// 		ft_putstr("pb\n");
// 	}
// 	return (tab);
// }

/* 0 ra
 1 rb
 2 rr
*/
t_liste	*pre_rotate(t_liste *stack, int option)
{
	if (option == 0)
	{
		stack = rotate(stack);
		ft_putstr("ra\n");
	}
	else if (option == 1)
	{
		stack = rotate(stack);
		ft_putstr("rb\n");
	}
	return (stack);
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

int	*argtotab(char **argv)
{
	int		i;
	int		*tab;

	i = 1;
	tab = NULL;
	tab = malloc((ft_strlen(argv) - 1) * 4);
	while (argv[i])
	{
		tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (tab);
}

t_liste	*listcpy(t_liste *stacka)
{
	t_liste		*cpy;
	t_element	*ptr;
	int			nbr;
	int			i;

	cpy = listinit();
	ptr = stacka->first;
	i = 0;
	while (ptr->next->next)
	{
		nbr = ptr->nbr;
		insertlist(cpy, nbr);
		ptr = ptr->next;
	}
	return (cpy);
}

int	stack_sorted(t_liste *stacka, int argc)
{
	int		i;
	int		*value;
	t_liste	*stacktest;

	i = 0;
	stacktest = listcpy(stacka);
	value = malloc(sizeof(int) * (argc - 1));
	while (i < (argc - 1))
	{
		value[i] = unpile(stacktest);
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (value[i] < value[i + 1])
		{
			free (value);
			removelist(stacktest);
			return (0);
		}
		i--;
	}
	removelist(stacktest);
	free (value);
	return (1);
}

int	a_sorted(int *value)
{
	int		i;

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

int	*order(int *stacka, int argc)
{
	int		i;
	int		j;
	int		*nbr;

	i = 0;
	nbr = malloc(sizeof(stacka));
	while (i < argc)
	{
		j = 0;
		nbr[i] = 0;
		while (j < argc)
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
	int		j;
	int		ret;

	i = 0;
	j = 0;
	while (i < (sizeof(stack) / 4))
	{
		if (stack[i] > j)
			j = stack[i];
		i++;
	}
	ret = 1;
	while (j > 0)
	{
		j /= 2;
		ret++;
	}
	return (ret);
}

void	radix_sort(t_liste *stacka, int argc)
{
	int		i;
	int		nbr;
	t_liste	*stackb;

	stackb = listinit();
	// int i = 0;
	// stacka = rotate(stacka);
	// while (i < (argc - 1))
	// {
	// 	printf("%d\n", unpile(stacka));
	// 	i++;
	// }
	while (!stack_sorted(stacka, argc))
	{
		i = 0;
		while (i < (argc - 1))
		{
			nbr = stacka->first->nbr;
			if ((nbr >> i) & 1)
				pre_rotate(stacka, 0);
			else
				pre_push(stacka, stackb, 1);
		}
		while (stackb->first)
			pre_push(stackb, stacka, 0);
	}
}

t_liste	*valuetoliste(int *value, int argc)
{
	t_liste	*stacka;
	int		i;

	stacka = listinit();
	i = argc - 1;
	while (i >= 0)
	{
		insertlist(stacka, value[i]);
		i--;
	}
	return (stacka);
}

int main(int argc, char **argv)
{
	int		*value;
	int		*index;
	t_liste	*stacka;
	t_liste	*stackb;

	value = argtotab(argv);//fonctionne
	if (ft_check(argv, value) == -1)
	{
		free (value);
		return (ft_error());
	}
	stacka = valuetoliste(value, argc);//value dans liste
	stackb = listinit();
	radix_sort(stacka, argc);
	// int i = 0;
	// while (i < (argc - 1))
	// {
	// 	printf("%d\n", unpile(stacka));
	// 	i++;
	// }
	free (value);
	removelist(stacka);
	removelist(stackb);
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