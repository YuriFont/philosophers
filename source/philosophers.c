#include "philosophers.h"
#include <stdio.h>

void	computation(void *add)
{
	int	i;

	i = 10;
	while (add <= i)
		printf("%d", (long)add++);
}

int	main(void)
{
	pthread_t	thr1;
	pthread_t	thr2;

	long	values1 = 1;
	long	values2 = 2;

	computation((void *) &values1);
	computation((void *) &values2);
	return (0);
}
