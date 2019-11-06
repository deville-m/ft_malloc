/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:16:16 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/06 17:58:38 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
# define CHUNK_H

# include <stddef.h>

typedef enum		e_pos
{
	START,
	MID,
	END
}					t_pos;

typedef struct		s_header
{
	size_t			size;
	t_pos			pos;
	size_t			free;
	struct s_header	*next;
	struct s_header	*prev;
}					t_header;

typedef struct		s_footer
{
	size_t			size;
}					t_footer;

extern t_header		*g_free[3];
extern t_header		*g_malloc;
extern size_t		g_page_size;

void				coalesce(t_header *left, t_header *right);
t_header			*get_chunk(size_t size, t_header **free_lst);
t_footer			*get_footer(t_header *header);
void				insert(t_header *chunk, t_header **free_lst);
t_header			*pop(t_header *chunk, t_header **head);

#endif
