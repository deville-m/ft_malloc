/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 20:02:04 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 01:56:45 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory.h"
#include "dlst.h"

void	*ft_dlst_to_tab(t_dlist *lst)
{
	size_t	len;
	void	*res;
	char	*p;

	if (!lst)
		return (NULL);
	len = ft_dlstlen(lst);
	if (!(res = (char *)malloc(lst->content_size * (len + 1))))
		return (NULL);
	p = (char *)res;
	while (lst)
	{
		ft_memcpy(p, lst->content, lst->content_size);
		p += lst->content_size;
		lst = lst->next;
	}
	return (res);
}
