/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:39:16 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/06 18:09:48 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <sys/mman.h>
#include "ft_malloc.h"
#include "chunk.h"

int			more_core(t_header **free_lst)
{
	t_header	*addr;
	size_t		size;

	size = (100 * MEDIUM + g_page_size - 1) / g_page_size * g_page_size;
	addr = (t_header *)mmap(NULL,
							size,
							PROT_READ | PROT_WRITE,
							MAP_SHARED | MAP_ANONYMOUS,
							-1, 0);
	if (!addr)
		return (0);
	addr->size = size - sizeof(t_header) - sizeof(t_footer);
	addr->free = true;
	addr->pos = START;
	addr->next = addr;
	addr->prev = addr;
	get_footer(addr)->size = addr->size;
	insert(addr, free_lst);
	return (1);
}

t_header	*internal_malloc(size_t size, t_header **free_lst)
{
	t_header *temp;

	temp = get_chunk(size, free_lst);
	if (!temp && !more_core(free_lst))
		return (NULL);
	if (!temp)
		temp = get_chunk(size, free_lst);
	return (temp);
}

void		*bigalloc(size_t size)
{
	t_header	*addr;

	addr = (t_header *)mmap(NULL,
							size,
							PROT_READ | PROT_WRITE,
							MAP_SHARED | MAP_ANONYMOUS,
							-1, 0);
	if (!addr)
		return (NULL);
	addr->size = size - sizeof(t_header) - sizeof(t_footer);
	addr->free = false;
	get_footer(addr)->size = addr->size;
	return (addr);
}

void		*malloc(size_t size)
{
	t_header	*temp;
	size_t		nb_units;
	size_t		real_size;

	if (!size)
		return (NULL);
	nb_units = (size + CHKRES - 1) / CHKRES;
	real_size = nb_units * CHKRES;
	if (real_size < TINY)
		temp = internal_malloc(real_size, &g_free[0]);
	else if (real_size < MEDIUM)
		temp = internal_malloc(real_size, &g_free[1]);
	else
		temp = bigalloc(((real_size + sizeof(t_header) + sizeof(t_footer)
						+ g_page_size - 1) / g_page_size) * g_page_size);
	if (!temp)
		return (NULL);
	insert(temp, &g_malloc);
	return ((void *)temp + sizeof(t_header));
}
