/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:10:56 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/07 15:21:36 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	lstlen(t_header *head)
{
	size_t		i;
	t_header	*walk;

	if (!head)
		return (0);
	i = 1;
	walk = head->next;
	while (walk != head)
	{
		++i;
		walk = walk->next;
	}
	return (i);
}
