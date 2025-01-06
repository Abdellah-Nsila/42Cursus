/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:45:03 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/06 13:14:03 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"






//! Practical use case for Fork() and Pipe() (Home Work)
// int	main(int ac, char **av)
// {
// 	//TODO fix 4 size (use modulo, just an calc logic issue the main goal of pipe is done XD)
// 	int	arr[] = {1, 2, 3, 4};
// 	int	fd[2];
// 	int	id1;
// 	int	id2;
// 	int	size;
// 	int	ramaining;
// 	int	half;

// 	size = sizeof(arr) / sizeof(int);
// 	ramaining = size - (size / 3);
// 	half = ramaining / 2;
// 	if (size == 1)
// 		return (printf("\nThe sum of arr: %d\n", arr[0]), 0);
// 	if (pipe(fd) == -1)
// 		return (printf("Error in opening pipe\n"), 1);
// 	id1 = fork();
// 	wait(NULL);
// 	if (id1 != 0)
// 		id2 = fork();
// 	wait(NULL);
// 	if (id1 == 0)
// 	{
// 		close(fd[0]);
// 		int sum1;
// 		sum1 = 0;
// 		sum1 = ft_n_sum(arr, 0, half);
// 		if (write(fd[1], &sum1, sizeof(int)) == -1)
// 			return (printf("Error in writing to pipe\n"), 1);
// 		close(fd[1]);
// 	}
// 	else if (id2 == 0)
// 	{
// 		int sum2;
// 		sum2 = 0;
// 		if (read(fd[0], &sum2, sizeof(int)) == -1)
// 			return (printf("Error in reading from pipe\n"), 1);
// 		sum2 += ft_n_sum(arr, half, half);
// 		if (write(fd[1], &sum2, sizeof(int)) == -1)
// 			return (printf("Error in writing to pipe\n"), 1);
// 		close(fd[0]);
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		int sum3;
// 		sum3 = 0;
// 		if (read(fd[0], &sum3, sizeof(int)) == -1)
// 			return (printf("Error in reading from pipe\n"), 1);
// 		sum3 += ft_n_sum(arr, half*2, size - ramaining);
// 		close(fd[0]);
// 		printf("\nThe sum of arr: %d\n", sum3);
// 	}
// 	return (0);
// }

//! Practical use case for Fork() and Pipe()
// int	main(int ac, char **av)
// {
// 	int	arr[] = {1, 2, 3, 8, 9, 7, 5, 6};
// 	int	fd[2];
// 	int	id;
// 	int	size;
// 	int	half;

// 	size = sizeof(arr) / sizeof(int);
// 	half = size - (size / 2);
// 	if (pipe(fd) == -1)
// 		return (printf("Error in opening pipe\n"), 1);
// 	id = fork();
// 	if (id == -1)
// 		return (printf("Error in forking process\n"), 1);
// 	wait(NULL);
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		int sum1;
// 		sum1 = ft_n_sum(arr, 0, half);
// 		if (write(fd[1], &sum1, sizeof(int)) == -1)
// 			return (printf("Error in writing to pipe\n"), 1);
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		int sum2;
// 		if (read(fd[0], &sum2, sizeof(int)) == -1)
// 			return (printf("Error in reading from pipe\n"), 1);
// 		sum2 += ft_n_sum(arr, half, size / 2);
// 		close(fd[0]);
// 		printf("\nThe sum of arr: %d\n", sum2);
// 	}
// 	return (0);
// }

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