/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:15:27 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 15:50:52 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_arriter(void *array, size_t nmemb, size_t size, void (*f)(void *))
{
	char *p;

	if (!array || !size || !nmemb || !f)
		return ;
	p = (char *)array;
	while (size)
	{
		f(p);
		p += nmemb;
		size -= 1;
	}
}
