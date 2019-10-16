/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstprepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:00:05 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/06 17:34:13 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

void	ft_clstprepend(t_clist **head, t_clist *new)
{
	if (!head)
		return ;
	ft_clstappend(head, new);
	*head = (*head)->prev;
}
