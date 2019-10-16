/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:40:34 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/06 17:30:56 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLST_H
# define CLST_H

# include "dlst.h"

typedef	t_dlist	t_clist;

t_clist	*ft_clstnew(void const *content, size_t content_size);
void	ft_clstappend(t_clist **head, t_clist *new);
void	ft_clstprepend(t_clist **head, t_clist *new);
t_clist	*ft_clstpop(t_clist **head);
size_t	ft_clstlen(t_clist *lst);
void	ft_clstiter(t_clist *lst, void (*f)(t_clist *elem));

#endif
