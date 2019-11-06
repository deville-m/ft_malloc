/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:06:52 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/06 13:19:22 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_malloc.h"
#include "chunk.h"
#include "memory.h"

void	*realloc(void *ptr, size_t size)
{
	t_header	*chunk;
	void		*p;
	size_t		final;

	if (!ptr)
		return (malloc(size));
	if (!(p = malloc(size)))
		return (NULL);
	chunk = ptr - sizeof(t_header);
	final = (size < chunk->size) ? size : chunk->size;
	ft_memcpy(p, ptr, final);
	free(ptr);
	return (p);
}
