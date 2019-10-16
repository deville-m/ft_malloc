/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:02:54 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/06 17:33:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

size_t	ft_clstlen(t_clist *lst)
{
	size_t	i;
	t_clist	*walk;

	if (!lst)
		return (0);
	i = 1;
	walk = lst->next;
	while (walk != lst)
	{
		i += 1;
		walk = walk->next;
	}
	return (i);
}
