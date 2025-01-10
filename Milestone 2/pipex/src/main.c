/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:45:03 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/10 17:51:04 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"


int 	main(void)
{
	int pid = fork();
	if (pid == -1)
	{	
		perror("Error in forking\n");
		return (1);
	}

	if (pid == 0)
	{
		char	cmd[] = "/usr/bin/ping";
		char	*arg_vec[] = {"ping","-c", "3", "google.com", NULL};
		char	*env_vec[] = {NULL};

		int	fd = open("pingResult.txt", O_WRONLY | O_CREAT, 0777);
		if (fd == -1)
		{	
			printf("Error on opening file\n");
			return (1);
		}
		printf("The fd of pingResult.txt %d\n", fd);
		int	fd2 = dup2(fd, STDOUT_FILENO);

		printf("========= Start execution execve(): %s =========\n", cmd);
		if (execve(cmd, arg_vec, env_vec) == -1)
		{
			perror("Error in execve()\n");
			return (2);
		}
	}
	else
	{
		int	wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			int	statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("Success, exit(%d)\n", statusCode);
			else
				printf("Failure, exit(%d)\n", statusCode);
		}
		printf("Child Process executed Go to Main Process\n");
	}
	return (0);
}

//! EXECVE() + DUP2()
// int	main()
// {
// 	char	cmd[] = "/usr/bin/ping";
// 	char	*arg_vec[] = {"ping","-c", "1", "google.com", NULL};
// 	char	*env_vec[] = {NULL};

// 	int	fd = open("pingResult.txt", O_WRONLY | O_CREAT, 0777);
// 	if (fd == -1)
// 		printf("Error on opening file\n");
// 	printf("The fd of pingResult.txt %d\n", fd);
// 	int	fd2 = dup2(fd, STDOUT_FILENO);
// 	// printf("The duplicated fd of pingResult.txt %d\n", fd2);

// 	printf("======== Start execution execve(): %s ========\n", cmd);
// 	if (execve(cmd, arg_vec, env_vec) == -1)
// 	{
// 		perror("Error in execve()\n");
// 	}
// 	printf("================================================\n");
// 	printf("Error detected\n");
// 	return (0);
// }

//! EXECVE(), execute onother executable (Ex: C programme)
// int 	main(void)
// {
// 	char	cmd[] = "./arg.out";
// 	char	*arg_vec[] = {"./arg.out", "one", "two", "three", NULL};
// 	char	*env_vec[] = {NULL};

// 	printf("======== Start execution execve(): %s ========\n", cmd);
// 	if (execve(cmd, arg_vec, env_vec) == -1)
// 	{
// 		perror("Error in execve()\n");
// 	}
// 	printf("================================================\n");
// 	printf("Error detected\n");
// 	return (0);
// }

//! EXECVE(), execute a Shell command
// int 	main(void)
// {
// 	char	cmd[] = "/usr/bin/ls";
// 	char	*arg_vec[] = {"ls", "-l", "/home", NULL};
// 	char	*env_vec[] = {NULL};

// 	printf("======== Start execution execve(): %s ========\n", cmd);
// 	if (execve(cmd, arg_vec, env_vec) == -1)
// 	{
// 		perror("Error in execve()\n");
// 	}
// 	printf("================================================\n");
// 	printf("Error detected\n");
// 	return (0);
// }

// ! Two way communication between processes (using pipes) in C
//? Methode [1]
// int 	main(int ac, char **av)
// {
// 	int	fd1[2];
// 	int	fd2[2];
// 	int	id;	

// 	if (pipe(fd1) == -1)
// 			printf("Error in create pipe fd1\n");
// 	if (pipe(fd2) == -1)
// 			printf("Error in create pipe fd2\n");
// 	id = fork();
// 	if (id == 0)
// 	{
// 		close(fd2[1]);
// 		close(fd1[0]);
// 		int	x;
// 		if (read(fd2[0], &x, sizeof(int)) == -1)
// 			printf("Error in reading from pipe\n");
// 		x *= 4;
// 		if (write(fd1[1], &x, sizeof(int)) == -1)
// 		printf("Error in writing to pipe\n");
// 		close(fd2[0]);
// 		close(fd1[1]);
// 	}
// 	else
// 	{
// 		close(fd1[1]);
// 		close(fd2[0]);
// 		int num = 5;
// 		if (write(fd2[1], &num, sizeof(int)) == -1)
// 			printf("Error in writing to pipe\n");

// 		if (read(fd1[0], &num, sizeof(int)) == -1)
// 			printf("Error in reading from pipe\n");
// 		printf("The num: %d\n", num);
// 		close(fd1[0]);
// 		close(fd2[1]);
// 		wailt(NULL);
// 	}
// 	close(fd1[0]);
// 	close(fd2[1]);
// 	return (0);
// }

//? Methode [2]
// int 	main(int ac, char **av)
// {
// 	int	fd[2];
// 	int	id;
// 	int num;
	
// 	num = 5;
// 	if (pipe(fd) == -1)
// 		printf("Error in create pipe\n");
// 	if (write(fd[1], &num, sizeof(int)) == -1)
// 		printf("Error in writing to pipe\n");
// 	id = fork();
// 	wait(NULL);
// 	if (id == 0)
// 	{
// 		int	x;
// 		if (read(fd[0], &x, sizeof(int)) == -1)
// 			printf("Error in reading from pipe\n");
// 		x *= 4;
// 		if (write(fd[1], &x, sizeof(int)) == -1)
// 		printf("Error in writing to pipe\n");
// 	}
// 	else
// 	{
// 		if (read(fd[0], &num, sizeof(int)) == -1)
// 			printf("Error in reading from pipe\n");
// 		printf("The num: %d\n", num);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	return (0);
// }

//! Fifo => mkfifo()
// int	main(int ac, char **av)
// {
// 	int		fd;
// 	int		arr[5] = {5, 9, 17, 20, 3};
// 	int		i;
// 	int		rb;
// 	int		sum;

// 	if (!ac && !av)
// 		return (1);
// 	if (mkfifo("fifoData", 0777) == -1)
// 	{
// 		if (errno != EEXIST)
// 		{
// 			printf("Could not create fifo file\n");
// 			return (1);
// 		}
// 	}
// 	// Write Numbers to Fifo
// 	fd = open("fifoData", O_WRONLY);
// 	if (fd == -1)
// 		printf("Error in opening file");
// 	if (write(fd, arr, sizeof(arr)) == -1)
// 		printf("Error in writing file");
// 	i = 0;
// 	while (i <  sizeof(arr) / 4)
// 	{
// 		printf("Num: %d\n", arr[i]);
// 		i++;
// 	}
// 	close(fd);

// 	// Read Sum Numbers from Fifo
// 	fd = open("fifoData", O_RDONLY);
// 	if (fd == -1)
// 		printf("Error in opening file");
// 	if (read(fd, &sum, sizeof(int)) == -1)
// 		printf("Error in reading file");
//     printf("Sum: %d\n", sum);
// 	close(fd);
// 	return (0);
// }

//! Fifo => mkfifi()
// int	main(int ac, char **av)
// {
// 	int		fd;
// 	int		i;

// 	if (!ac && !av)
// 		return (1);
// 	if (mkfifo("myfifo1", 0777) == -1)
// 	{
// 		if (errno != EEXIST)
// 		{
// 			printf("Could not create fifo file\n");
// 			return (1);
// 		}
// 	}
// 	fd = open("myfifo1", O_RDWR);
// 	if (fd == -1)
// 		printf("Error in opening file");
// 	i = 0;
// 	while (i < 100)
// 	{
// 		if (write(fd, "Hello\n", 7) == -1)
// 			printf("Error in writing file");
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }


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