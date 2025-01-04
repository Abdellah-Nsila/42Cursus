#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void	ft_printnums(int n)
{
	int i;

	i = 1;
	while (i <= n)
	{
		printf("%d ", i);
		fflush(stdout);
		i++;
	}
}

int	main(int ac, char **av)
{
	int id = fork();
	printf("id: %d\n", id);
	// if (id == 0)
	// 	ft_printnums(5);
	// else
	// 	ft_printnums(10);
	if (id != 0)
		wait();
	ft_printnums(5);
	if (id != 0)
		printf("\n");
}