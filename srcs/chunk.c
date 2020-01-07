/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:35:24 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/07 18:04:49 by mdeville         ###   ########.fr       */
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


//TODO: simplify this function
t_header	*split_chunk(size_t size, t_header *chunk)
{
	t_header	*left;

	left = (void *)chunk + sizeof(t_header) + size + sizeof(t_footer);
	left->size = chunk->size - size - sizeof(t_footer) - sizeof(t_header);
	left->free = true;
	left->pos = (chunk->pos == END) ? END : MID;
	chunk->pos = (chunk->pos == END) ? MID : chunk->pos;
	left->next = chunk->next;
	left->prev = chunk;
    left->next->prev = left;
    chunk->prev->prev = (chunk->prev->prev == chunk) ? left : chunk->prev->prev; 
	chunk->prev = (chunk->prev == chunk) ? left : chunk->prev;
	chunk->next = left;
	chunk->size = size;
	get_footer(chunk)->size = size;
	get_footer(left)->size = left->size;
	return (chunk);
}

t_header	*extract_chunk(size_t size, t_header *chunk, t_header **free_lst)
{
	if (size != chunk->size)
		chunk = split_chunk(size, chunk);
	chunk = pop(chunk, free_lst);
	//insert(chunk, &g_malloc);
	chunk->free = false;
	return (chunk);
}

t_header	*get_chunk(size_t size, t_header **free_lst)
{
	t_header *walk;

	walk = *free_lst;
	while (*free_lst)
	{
		if (size == walk->size
			|| size + sizeof(t_header) + sizeof(t_footer) < walk->size)
			return (extract_chunk(size, walk, free_lst));
		if (walk->next == *free_lst)
			break ;
		walk = walk->next;
	}
	return (NULL);
}
