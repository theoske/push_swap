#ifndef _PUSH_SWAP_H_
#define _PUSH_SWAP_H_

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

t_liste	        *listinit(void);
void            insertlist(t_liste *liste, int newnbr);
void            removelist(t_liste *liste);
int             unpile(t_liste *liste);
unsigned int	ft_strlen(const char *s);
void	        ft_putstr(char *str);
t_liste	        *rotate(t_liste *stack);
t_stacks	    pushb(t_stacks stacks);
t_stacks	    pusha(t_stacks stacks);
t_stacks	    pre_push(t_stacks stacks, int nb);
t_liste	        *pre_rotate(t_liste *stack, int option);
int	            ft_finder(const char *nptr);
int	            ft_atoi(const char *nptr);
int	            *argtotab(char **argv);
int         	stack_sorted(t_liste *stacka, int argc);
int	            a_sorted(int *value);
int	            dup_check(int *value);
int	            nbr_check(char **argv);
int	            ft_strncmp(const char *str1, const char *str2, size_t n);
int	            neglim_check(char *str);
int	            poslim_check(char *str);
int	            lim_check(char **argv);
int	            ft_error(void);
int	            ft_check(char **argv, int *value);
int	            *order(int *value, int argc);
int	            ft_bigbit(int *stack);
t_stacks    	radix_sort(t_stacks stacks, int argc);
t_liste	        *valuetoliste(int *value, int argc);

#endif