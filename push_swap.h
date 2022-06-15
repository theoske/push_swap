/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:53:43 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/06/15 13:59:05 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_element	t_element;
struct s_element
{
	int			nbr;
	t_element	*next;
};

typedef struct s_liste
{
	t_element	*first;
}	t_liste;

typedef struct s_stacks
{
	t_liste		*stacka;
	t_liste		*stackb;
}	t_stacks;

t_liste			*listinit(void);
void			insertlist(t_liste *liste, int newnbr);
void			removelist(t_liste *liste);
int				unpile(t_liste *liste);
unsigned int	ft_strlen(const char *s);
void			ft_putstr(char *str);
t_liste			*rotate(t_liste *stack);
t_stacks		pushb(t_stacks stacks);
t_stacks		pusha(t_stacks stacks);
t_stacks		pre_push(t_stacks stacks, int nb);
t_liste			*pre_rotate(t_liste *stack, int option);
int				ft_finder(const char *nptr);
int				ft_atoi(const char *nptr);
int				*argtotab(char **argv, int argc);
int				stack_sorted(t_liste *stacka);
int				a_sorted(int *value, int argc);
int				dup_check(int *value, int argc);
int				nbr_check(char **argv);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				neglim_check(char *str);
int				poslim_check(char *str);
int				lim_check(char **argv);
int				ft_error(void);
int				ft_check(char **argv, int *value, int argc);
int				*order(int *value, int argc);
int				ft_bigbit(int *stack);
t_stacks		radix_sort(t_stacks stacks, int argc);
t_liste			*valuetoliste(int *value, int argc);
t_stacks		four_sized(t_stacks stacks);
t_stacks		three_sized(t_stacks stacks);
t_stacks		rra(t_stacks stacks);
t_stacks		swapa(t_stacks stacks);
t_stacks		small_sort(t_stacks stacks, int argc);
t_stacks		nameless(t_stacks stacks, int tab);
int				find_biggest(t_liste *stack);
t_stacks		five_sized_operations(t_stacks stacks);
t_stacks		five_sized(t_stacks stacks);

#endif