#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include "ft_malloc.h"

#define SIZE 100

void *arr[SIZE];

void	clear_arr(int sig)
{
	size_t i = 0;

	write(1, "FREE ALL MEMORY\n", 16);
	while (i < SIZE)
	{
		if (arr[i])
		{
			free(arr[i]);
			show_alloc_mem();
		}
		i++;
	}
	exit(0);
}

int main()
{
	size_t i;
	size_t size;

	signal(SIGINT, clear_arr);
	bzero(arr, sizeof(void *) * SIZE);
	srand(time(NULL));
	i = 1;
	while (1)
	{
		i = rand() % SIZE;
		if (arr[i])
		{
			write(1, "free 0x", 7);
			putnbr((size_t)arr[i], 16);
			write(1, "\n", 1);
			show_alloc_mem();
			free(arr[i]);
			arr[i] = NULL;
		}
		else
		{
			size = rand() % (MEDIUM + 1);
			write(1, "malloc ", 7);
			putnbr(size, 10);
			write(1, "\n", 1);
			show_alloc_mem();
			arr[i] = malloc(size);
			memset(arr[i], 'A', size);
		}
		show_alloc_mem();
	}
}
