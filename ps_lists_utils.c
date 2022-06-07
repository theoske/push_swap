/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lists_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:31:36 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/06/07 17:56:37 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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