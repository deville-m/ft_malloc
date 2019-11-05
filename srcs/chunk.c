/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:35:24 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/05 17:11:10 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_malloc.h"
#include "chunk.h"

t_footer	*get_footer(t_header *header)
{
	return ((void *)header +
			sizeof(t_header) +
			header->size);
}

t_header	*split_chunk(size_t size, t_header *chunk)
{
	t_header	*left;

	left = (void *)chunk + sizeof(t_header) + size + sizeof(t_footer);
	left->size = chunk->size - size - sizeof(t_footer) - sizeof(t_header);
	left->free = true;
	left->pos = (chunk->pos == END) ? END : MID;
	chunk->pos = (chunk->pos == END) ? MID : chunk->pos;
	left->next = (chunk->next == chunk) ? left : chunk->next;
	left->prev = (chunk->prev == chunk) ? left : chunk->prev;
	left->next->prev = left;
	left->prev->next = left;
	get_footer(left)->size = left->size;
	chunk->size = size;
	chunk->next = left;
	get_footer(chunk)->size = size;
	return (chunk);
}

t_header	*extract_chunk(size_t size, t_header *chunk, t_header **free_lst)
{
	if (size + sizeof(t_header) + sizeof(t_footer) <= chunk->size)
		split_chunk(size, chunk);
	else
	{
		chunk->prev->next = chunk->next;
		chunk->next->prev = chunk->prev;
	}
	if (chunk == *free_lst)
		*free_lst = (chunk->next == chunk) ? NULL : chunk->next;
	chunk->free = false;
	return (chunk);
}

t_header	*get_chunk(size_t size, t_header **free_lst)
{
	t_header *walk;

	walk = *free_lst;
	while (*free_lst)
	{
		if (size < walk->size)
			return (extract_chunk(size, walk, free_lst));
		if (walk->next == *free_lst)
			break;
		walk = walk->next;
	}
	return (NULL);
}
