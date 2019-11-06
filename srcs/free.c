/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:56:01 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/06 13:17:58 by mdeville         ###   ########.fr       */
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
size_t		g_page_size = 4096;

void		restore(t_header *chunk, t_header **free_lst)
{
	t_header *walk;

	if (!*free_lst)
		*free_lst = chunk;
	else
	{
		walk = *free_lst;
		while (walk < chunk && walk->next != *free_lst)
			walk = walk->next;
		chunk->next = walk;
		chunk->prev = walk->prev;
		walk->prev = chunk;
		chunk->prev->next = chunk;
	}
}

void		free(void *p)
{
	t_header *chunk;
	size_t real_size;

	if (!p)
		return;
	chunk = p - sizeof(t_header);
	if (chunk->free)
		return (void)write(2, "Double free\n", 12);
	chunk->free = false;
	real_size = chunk->size;
	if (real_size < TINY)
		restore(chunk, &g_free[0]);
	else if (real_size < MEDIUM)
		restore(chunk, &g_free[1]);
	else
		munmap(chunk, chunk->size + sizeof(t_header) + sizeof(t_footer));
}
