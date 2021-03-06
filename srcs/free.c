/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:56:01 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/06 16:08:48 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/mman.h>
#include "ft_malloc.h"
#include "chunk.h"

t_header	*g_free[3] = {NULL, NULL, NULL};
t_header	*g_malloc = NULL;
size_t		g_page_size = 4096;

int			valid(t_header *chunk)
{
	t_header *walk;

	walk = g_malloc;
	while (1)
	{
		if (walk == chunk)
			return (1);
		if (walk->next == g_malloc)
			break ;
		walk = walk->next;
	}
	return (0);
}

void		coalesce(t_header *chunk)
{
	t_header	*prev;
	t_header	*next;

	prev = chunk->prev;
	if ((void *)prev + sizeof(t_header) + prev->size + sizeof(t_footer) == chunk)
	{
		prev->next = chunk->next;
		prev->size = prev->size + sizeof(t_footer) + sizeof(t_header) + chunk->size;
		prev->next->prev = prev;
		get_footer(prev)->size = prev->size;
	}
	next = chunk->next;
	if ((void *)chunk + sizeof(t_header) + chunk->size + sizeof(t_footer) == next)
	{
		chunk->next = next->next;
		chunk->size = chunk->size + sizeof(t_footer) + sizeof(t_header) + next->size;
		next->next->prev = chunk;
		get_footer(chunk)->size = chunk->size;
	}
}

void		restore(t_header *chunk, size_t real_size)
{
	if (real_size < TINY)
		insert(chunk, &g_free[0]);
	else if (real_size < MEDIUM)
		insert(chunk, &g_free[1]);
	coalesce(chunk);
}

void		free(void *p)
{
	t_header	*chunk;
	size_t		real_size;

	chunk = p - sizeof(t_header);
	if (!p || !valid(chunk))
		return ;
	if (chunk->free)
		return (void)write(2, "Double free\n", 12);
	chunk->free = true;
	chunk = pop(chunk, &g_malloc);
	real_size = chunk->size;
	if (real_size < TINY)
		insert(chunk, &g_free[0]);
	else if (real_size < MEDIUM)
		insert(chunk, &g_free[1]);
	else
		munmap(chunk, chunk->size + sizeof(t_header) + sizeof(t_footer));
}
