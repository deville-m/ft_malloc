#include <unistd.h>
#include <stdlib.h>
#include "ft_malloc.h"

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

int main()
{
	void *p;
	size_t i;
	size_t size;

	srand(1);
	for (i = 0; i < 1000; i++)
	{
		size = rand() % 1024;
		write(1, "\e[31mmalloc\e[0m\n", 16);
		putnbr(size, 10);
		write(1, "\n", 1);
		p = malloc(size);
		show_alloc_mem();
		if (i % 2)
		{
			write(1, "\e[32mfree\e[0m\n", 14);
			free(p);
			show_alloc_mem();
		}
	}
}
