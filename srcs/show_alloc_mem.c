/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:28:41 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/05 17:18:33 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_malloc.h"
#include "ft_string.h"
#include "chunk.h"

void	putnbr(size_t n, size_t base)
{
	char buf[] = "0123456789abcdef";

	if (n < base)
		write(1, buf + n, 1);
	else
	{
		putnbr(n / base, base);
		write(1, buf + n % base, 1);
	}
}

void	print_header(t_header *h)
{
	write(1, "0x", 2);
	putnbr((size_t)h, 16);
	write(1, " / ", 3);
	write(1, "0x", 2);
	putnbr((size_t)((void *)h + sizeof(t_header)), 16);
	write(1, " - ", 3);
	write(1, "0x", 2);
	putnbr((size_t)((void *)h + sizeof(t_header) + h->size), 16);
	write(1, " : ", 3);
	putnbr(h->size, 10);
	write(1, " octets\n", 8);
}

void	printlst(const char *name, t_header *lst)
{
	t_header *walk;

	write(1, name, ft_strlen(name));
	write(1, "0x", 2);
	putnbr((size_t)lst, 16);
	write(1, "\n", 1);

	if (!lst)
		return ;
	print_header(lst);
	walk = lst->next;
	while (walk != lst)
	{
		print_header(walk);
		walk = walk->next;
	}
	write(1, "\n", 1);
}

void	show_alloc_mem()
{
	printlst("TINY : ", g_free[0]);
	printlst("MEDIUM : ", g_free[1]);
	printlst("BIG : ", g_free[2]);
}
