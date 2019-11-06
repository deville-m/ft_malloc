/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:05:22 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/06 18:44:39 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "chunk.h"


// TODO: fix insert function
void		insert(t_header *chunk, t_header **free_lst)
{
	t_header *walk;

	if (!*free_lst)
		*free_lst = chunk;
	else
	{
		walk = *free_lst;
		while (walk < chunk && walk->next != *free_lst)
			walk = walk->next;
		if (walk->next == *free_lst)
		{
			walk->next = chunk;
			chunk->prev = walk;
			chunk->next = *free_lst;
			(*free_lst)->prev = chunk;
		}
		else
		{
			walk->prev->next = chunk;
			chunk->prev = walk->prev;
			chunk->next = walk;
			walk->prev = chunk;
		}
	}
}

t_header	*pop(t_header *chunk, t_header **head)
{
	if (chunk->next == chunk)
	{
		*head = NULL;
		chunk->next = NULL;
		chunk->prev = NULL;
		return (chunk);
	}
	chunk->prev->next = chunk->next;
	chunk->next->prev = chunk->prev;
	if (*head == chunk)
		*head = chunk->next;
	chunk->prev = NULL;
	chunk->next = NULL;
	return (chunk);
}
