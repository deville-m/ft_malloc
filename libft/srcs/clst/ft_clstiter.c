/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:13:00 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/06 17:25:44 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

void	ft_clstiter(t_clist *lst, void (*f)(t_clist *elem))
{
	t_dlist *walk;

	if (!lst)
		return ;
	f(lst);
	walk = lst->next;
	while (walk != lst)
	{
		f(walk);
		walk = walk->next;
	}
}
