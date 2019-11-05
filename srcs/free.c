/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:56:01 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/05 19:24:37 by mdeville         ###   ########.fr       */
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

int			find_lst(t_header *head, t_header *lst)
{
	t_header *walk;

	if (!lst)
		return (0);
	walk = lst->next;
	while (walk != lst)
	{
		if (walk == head)
			return (1);
		walk = walk->next;
	}
	return (0);
}

int			fuck_macos_read_posix(t_header *head)
{
	return (find_lst(head, g_free[0]) ||
			find_lst(head, g_free[1]) ||
			find_lst(head, g_free[2]));
}

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

	chunk = p - sizeof(t_header);
	if (!fuck_macos_read_posix(chunk))
		return (void)write(2, "Invalid pointer beeing freed\n", 29);
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
