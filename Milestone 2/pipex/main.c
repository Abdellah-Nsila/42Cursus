/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:45:03 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/05 14:53:24 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//! Pipe()
int	main(int ac, char **av)
{
	int	fd[2];
	int	id;
	int	x;
	int	y;

	if (pipe(fd) == -1)
		return (printf("Error in opening pipe\n"), 1);
	id  = fork();
	if (id == -1)
		return (printf("Error in forking process\n"), 1);
	if (id != 0)
		wait(NULL);
	if (id == 0)
	{
		close(fd[0]);
		printf("\nEnter a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
			return (printf("Error in writing to pipe\n"), 1);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &y, sizeof(int)) == -1)
			return (printf("Error in reading from pipe\n"), 1);
		printf("\nYour number is: %d\n", y);
		close(fd[0]);
	}
	return (0);
}

//! Multiple Fork()
// int	main(int ac, char **av)
// {
// 	int p;
// 	int id;

// 	p = 2;
// 	for (int i = 1; i <= p; i++)
// 	{
// 		printf("\n\n==================== Fork() N: %d =====================\n", i);
// 		id = fork();
// 		printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());
// 		wait(NULL);
// 	}
// 	if (id != 0)
// 		printf("2^%d = %d\n", p, power(2, p));
// 	return 0;
// }


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