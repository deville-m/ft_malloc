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

void		free(void *p)
{
	t_header	*chunk;
	size_t		real_size;

	if (!p)
		return ;
	chunk = p - sizeof(t_header);
	if (chunk->free)
		return (void)write(2, "Double free\n", 12);
	chunk->free = false;
	real_size = chunk->size;
	if (real_size < TINY)
		insert(chunk, &g_free[0]);
	else if (real_size < MEDIUM)
		insert(chunk, &g_free[1]);
	else
		munmap(chunk, chunk->size + sizeof(t_header) + sizeof(t_footer));
}
