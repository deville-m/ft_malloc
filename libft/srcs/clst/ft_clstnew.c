/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:06:08 by mdeville          #+#    #+#             */
/*   Updated: 2019/05/06 17:33:42 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"
#include "dlst.h"

t_clist	*ft_clstnew(void const *content, size_t content_size)
{
	return (ft_dlstnew(content, content_size));
}
