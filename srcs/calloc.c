/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:59:33 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/05 18:03:22 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "chunk.h"
#include "memory.h"

void	*calloc(size_t count, size_t size)
{
	size_t final;
	void *p;

	final = size * count;
	if (!(p = malloc(final)))
		return (NULL);
	ft_bzero(p, final);
	return (p);
}
