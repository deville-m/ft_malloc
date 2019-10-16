/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:27:57 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 18:21:39 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdlib.h>

t_list	*ft_lstpop(t_list **alst)
{
	t_list	*res;

	if (!alst || !*alst)
		return (NULL);
	res = *alst;
	*alst = (*alst)->next;
	res->next = NULL;
	return (res);
}
