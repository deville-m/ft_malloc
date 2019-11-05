/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:06:52 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/05 19:24:18 by mdeville         ###   ########.fr       */
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

	if (!(p = malloc(size)))
		return (NULL);
	chunk = ptr - sizeof(t_header);
	if (fuck_macos_read_posix(chunk))
		ft_memcpy(p, ptr, chunk->size);
	free(ptr);
	return (p);
}
