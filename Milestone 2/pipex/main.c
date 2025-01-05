#include "utils.h"

//! Multiple Fork()
int	main(int ac, char **av)
{
	int p;
	int id;
	// char *arr = {"First","Second","Third"};

	p = 2;
	for (int i = 1; i <= p; i++)
	{
		printf("\n\n==================== Fork() N: %d =====================\n", i);
		id = fork();
		printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());
		wait(NULL);
	}
	if (id != 0)
		printf("2^%d = %d\n", p, power(2, p));
	return 0;
}


//! Wait()
// int	main(int ac, char **av)
// {
// 	int id = fork();
// 	int res;

// 	res = wait(NULL);
// 	printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());
// 	if (res == -1)
// 		printf("No children to wait for.\n");
// 	else
// 		printf("%d finished execution.\n", res);
// 	return 0;
// }


//! Fork()
// int	main(int ac, char **av)
// {
// 	int id = fork();
	// int n;
	// if (id == 0)
	// 	n = 1;
	// else
	// 	n = 6;
	// if (id != 0)
	// 	wait(NULL);
	// ft_printnums(n);
	// if (id != 0)
	// 	printf("\n");
// }