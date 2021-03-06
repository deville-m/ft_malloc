/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:27:54 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/06 16:08:10 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define CHKRES 32

# define TINY 512
# define MEDIUM 4096

# include <stddef.h>

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			*calloc(size_t count, size_t size);
void			show_alloc_mem();
void			putnbr(size_t n, size_t base);
int				puts(const char *s);

#endif
