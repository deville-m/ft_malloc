/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:39:16 by mdeville          #+#    #+#             */
/*   Updated: 2019/10/16 19:33:48 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/mman.h>
#include "ft_malloc.h"
#include "header.h"

t_header	*internal_malloc(size_t nbu, t_header **free_lst)
{
	return (NULL);
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
	addr->size = size - sizeof(t_header);
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
		temp = internal_malloc(nb_units, &g_free[0]);
	else if (real_size < MEDIUM)
		temp = internal_malloc(nb_units, &g_free[1]);
	else
		temp = bigalloc(((real_size + sizeof(t_header) + g_page_size - 1) /
							g_page_size) * g_page_size);
	if (!temp)
		return (NULL);
	return ((void *)temp + sizeof(t_header));
}
