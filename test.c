#include <unistd.h>
#include "ft_malloc.h"

int main()
{
	void *p;
	size_t i;

	for (i = 0; i < 1000; i++)
	{
		write(1, "\e[31mmalloc\e[0m\n", 16);
		p = malloc(10);
		show_alloc_mem();
		if (i % 2)
		{
			write(1, "\e[32mfree\e[0m\n", 14);
			free(p);
			show_alloc_mem();
		}
	}
}
