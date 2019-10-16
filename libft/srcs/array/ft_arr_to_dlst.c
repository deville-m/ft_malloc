/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_dlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 01:20:25 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 15:51:46 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

t_dlist		*ft_tab_to_dlst(void *tab, size_t nmemb, size_t size)
{
	char	*p;
	t_dlist	*res;

	if (!tab || !nmemb || !size)
		return (NULL);
	res = NULL;
	p = (char *)tab;
	while (size)
	{
		ft_dlstprepend(&res, ft_dlstnew(p, nmemb));
		p += nmemb;
		size--;
	}
	ft_dlstreverse(&res);
	return (res);
}
