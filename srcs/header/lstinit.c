/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:54:30 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/07 15:21:26 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_header	*lstinit(void *chunk, size_t size)
{
	t_header *res;

	if (!chunk)
		return (NULL);
	res = (t_header *)chunk;
	res->magic = MAGIC;
	res->size = size;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}
