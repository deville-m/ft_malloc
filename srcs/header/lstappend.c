/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstappend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:06:21 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/07 15:21:07 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	lstappend(t_header **head, t_header *new)
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
