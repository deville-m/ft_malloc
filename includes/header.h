/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:16:16 by mdeville          #+#    #+#             */
/*   Updated: 2019/10/16 19:00:11 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stddef.h>

typedef enum        pos
{
    START,
    MID,
    END
} e_pos;

typedef struct		s_header
{
	size_t			size;
	e_pos           pos;
	size_t			free;
	struct s_header *next;
	struct s_header	*prev;
}					t_header;

extern t_header		*g_free[3];
extern size_t       g_page_size;

void				coalesce(t_header *left, t_header *right);
t_header			*lstpop(t_header **head);
void				lstprepend(t_header **head, t_header *new);
void				lstappend(t_header **head, t_header *new);
size_t				lstlen(t_header *head);

#endif
