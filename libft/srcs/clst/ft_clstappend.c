/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:40:10 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/06 17:31:52 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

void	ft_clstappend(t_clist **head, t_clist *new)
{
	if (!head)
		return ;
	if (!*head)
	{
		*head = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	new->prev = (*head)->prev;
	new->next = *head;
	new->prev->next = new;
	(*head)->prev = new;
}
