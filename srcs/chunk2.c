/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:05:22 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/07 17:54:03 by mdeville         ###   ########.fr       */
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
	else if ((*free_lst)->prev < chunk)
	{
		walk = (*free_lst)->prev;
		walk->next = chunk;
		chunk->prev = walk;
		(*free_lst)->prev = chunk;
		chunk->next = (*free_lst);
	}
	else
	{
		walk = *free_lst;
		while (walk < chunk)
			walk = walk->next;
		walk->prev->next = chunk;
		chunk->prev = walk->prev;
		walk->prev = chunk;
		chunk->next = walk;
		if (walk == *free_lst)
			*free_lst = chunk;
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
