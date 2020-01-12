#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include "ft_malloc.h"

#define SIZE 100

void *arr[SIZE];

int main()
{
	size_t i;
	size_t size;

	bzero(arr, sizeof(void *) * SIZE);
	srand(time(NULL));
	for (int j = 0; j < 100000; j++)
	{
		i = rand() % SIZE;
		if (arr[i])
		{
			write(1, "free 0x", 7);
			putnbr((size_t)arr[i], 16);
			write(1, "\n", 1);
			free(arr[i]);
			arr[i] = NULL;
		}
		else
		{
			size = rand() % (MEDIUM + 1);
			write(1, "malloc ", 7);
			putnbr(size, 10);
			write(1, "\n", 1);
			arr[i] = malloc(size);
			memset(arr[i], 'A', size);
		}
		//show_alloc_mem();
	}
	for (int j = 0; j < SIZE; j++)
	{
		if (arr[j])
			free(arr[j]);
	}
	show_alloc_mem();
}
