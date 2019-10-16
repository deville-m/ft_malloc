/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:07:42 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/06 17:40:30 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

t_clist	*ft_clstpop(t_clist **head)
{
	t_clist *tmp;

	if (!head)
		return (NULL);
	if (!*head)
		return (NULL);
	tmp = *head;
	if (tmp->next == tmp)
	{
		*head = NULL;
		return (tmp);
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	*head = tmp->next;
	return (tmp);
}
