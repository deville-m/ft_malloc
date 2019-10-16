/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstpop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:01:35 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/07 15:21:46 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_header	*lstpop(t_header **head)
{
	t_header *tmp;

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
