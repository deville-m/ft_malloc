/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:28:41 by mdeville          #+#    #+#             */
/*   Updated: 2019/11/07 17:35:37 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_malloc.h"
#include "ft_string.h"
#include "chunk.h"

int		puts(const char *s)
{
	while (*s)
		write(1, s++, 1);
	return (1);
}

void	putnbr(size_t n, size_t base)
{
	static char buf[] = "0123456789abcdef";

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
	puts("0x");
	putnbr((size_t)h, 16);
	puts(" / 0x");
	putnbr((size_t)((void *)h + sizeof(t_header)), 16);
	puts(" - 0x");
	putnbr((size_t)((void *)h + sizeof(t_header) + h->size), 16);
	puts(" : ");
	putnbr(h->size, 10);
	puts(" octets -- ");
	putnbr((size_t) h->prev, 16);
	puts(" -- ");
	putnbr((size_t) h->next, 16);
	puts("\n");
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

void	show_alloc_mem(void)
{
	printlst("TINY : ", g_free[0]);
	printlst("MEDIUM : ", g_free[1]);
	printlst("BIG : ", g_free[2]);
}
