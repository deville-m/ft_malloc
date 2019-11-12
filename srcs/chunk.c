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

t_header	*split_chunk(size_t size, t_header *chunk)
{
	t_header	*left;

	puts("before split\n");
	show_alloc_mem();
	left = (void *)chunk + sizeof(t_header) + size + sizeof(t_footer);
	left->size = chunk->size - size - sizeof(t_footer) - sizeof(t_header);
	left->free = true;
	left->pos = (chunk->pos == END) ? END : MID;
	chunk->pos = (chunk->pos == END) ? MID : chunk->pos;
	left->next = chunk->next;
	left->prev = chunk;
	chunk->prev = (chunk->prev == chunk) ? left : chunk->prev;
	chunk->next = left;
	chunk->size = size;
	get_footer(chunk)->size = size;
	get_footer(left)->size = left->size;
	puts("after split\n");
	show_alloc_mem();
	return (chunk);
}

t_header	*split_chunky(size_t size, t_header *chunk)
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
