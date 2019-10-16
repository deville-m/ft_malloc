/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstprepend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:09:19 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/10 11:57:15 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	lstprepend(t_header **head, t_header *new)
{
	if (!head)
		return ;
	lstappend(head, new);
	*head = (*head)->prev;
}
