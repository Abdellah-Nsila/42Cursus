/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:45:03 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/05 15:45:44 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_n_sum(int *arr, int start, int size)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (i < size)
	{
		s += arr[start + i];
		i++;
	}
	return (s);
}

//! Practical use case for Fork() and Pipe()
int	main(int ac, char **av)
{
	int	arr[] = {1, 2, 3, 8, 9, 7, 5, 6};
	int	fd[2];
	int	id;
	int	size;
	int	half;

	size = sizeof(arr) / sizeof(int);
	half = size - (size / 2);
	if (pipe(fd) == -1)
		return (printf("Error in opening pipe\n"), 1);
	id = fork();
	if (id == -1)
		return (printf("Error in forking process\n"), 1);
	wait(NULL);
	if (id == 0)
	{
		close(fd[0]);
		int sum1;
		sum1 = ft_n_sum(arr, 0, half);
		if (write(fd[1], &sum1, sizeof(int)) == -1)
			return (printf("Error in writing to pipe\n"), 1);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int sum2;
		if (read(fd[0], &sum2, sizeof(int)) == -1)
			return (printf("Error in reading from pipe\n"), 1);
		sum2 += ft_n_sum(arr, half, size / 2);
		close(fd[0]);
		printf("\nThe sum of arr: %d\n", sum2);
	}
	return (0);
}

// //! Pipe()
// int	main(int ac, char **av)
// {
// 	int	fd[2];
// 	int	id;
// 	int	x;
// 	int	y;

// 	if (pipe(fd) == -1)
// 		return (printf("Error in opening pipe\n"), 1);
// 	id  = fork();
// 	if (id == -1)
// 		return (printf("Error in forking process\n"), 1);
// 	if (id != 0)
// 		wait(NULL);
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		printf("\nEnter a number: ");
// 		scanf("%d", &x);
// 		if (write(fd[1], &x, sizeof(int)) == -1)
// 			return (printf("Error in writing to pipe\n"), 1);
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		if (read(fd[0], &y, sizeof(int)) == -1)
// 			return (printf("Error in reading from pipe\n"), 1);
// 		printf("\nYour number is: %d\n", y);
// 		close(fd[0]);
// 	}
// 	return (0);
// }

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