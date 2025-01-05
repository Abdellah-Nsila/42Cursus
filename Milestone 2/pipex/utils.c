#include "utils.h"

void	ft_printnums(int n)
{
	int i;

	i = n;
	while (i < n + 5)
	{
		printf("%d ", i);
		fflush(stdout);
		i++;
	}
}

int	power(int n, int power)
{
	int res;

	res = 1;
	while (power--)
		res *= n;
	return (res);
}