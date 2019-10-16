/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:27:57 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/12 18:58:45 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"
#include <stdlib.h>

t_dlist	*ft_dlstpop(t_dlist **alst)
{
	t_dlist	*res;

	if (!alst || !*alst)
		return (NULL);
	res = *alst;
	if ((*alst)->prev)
		(*alst)->prev->next = (*alst)->next;
	if ((*alst)->next)
	{
		(*alst)->next->prev = (*alst)->prev;
		*alst = (*alst)->next;
	}
	else
		*alst = (*alst)->prev;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}
