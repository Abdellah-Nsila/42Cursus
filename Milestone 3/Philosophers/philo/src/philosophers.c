/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:48:15 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/14 16:56:41 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_philo(t_philo *philo)
{
	srand(time(NULL));
	pthread_mutex_init(&philo->mutex, NULL);
	philo->score = 0;
}

void	*ft_get_prime()
{
	return (NULL);
}

//TODO You 10 thrades, an array of numbers, each tread, print a unique prime number

int	main()
{
	t_philo		philo;
	pthread_t	threads[THREADS];
	int			i = 0;
	int			sum = 0;
	int			*res;

	ft_init_philo(&philo);
	
	while (i < THREADS)
	{	
		if (pthread_create(&threads[i], NULL, &ft_get_prime, &philo) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		if (pthread_join(threads[i], (void **)&res) != 0)
			return (EXIT_FAILURE);
		sum += *res;
		i++;
	}
	printf("\nSum of Random Num: %d\n", sum);
	pthread_mutex_destroy(&philo.mutex);
	return (0);
}


//! Get the return of a function from tread
// void	*ft_random_num()
// {
// 	int	i;
// 	int	*res;

// 	res = malloc(sizeof(int));
// 	i = (rand() % 6) + 1;
// 	printf("Random Num in: %d\n", i);
// 	*res = i;
	
// 	return ((void *)res);
// }

// int	main()
// {
// 	t_philo		philo;
// 	pthread_t	threads[THREADS];
// 	int			i = 0;
// 	int			sum = 0;
// 	int			*res;

// 	ft_init_philo(&philo);
	
// 	while (i < THREADS)
// 	{	
// 		if (pthread_create(&threads[i], NULL, &ft_random_num, &philo) != 0)
// 			return (EXIT_FAILURE);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < THREADS)
// 	{
// 		if (pthread_join(threads[i], (void **)&res) != 0)
// 			return (EXIT_FAILURE);
// 		sum += *res;
// 		i++;
// 	}
// 	printf("\nSum of Random Num: %d\n", sum);
// 	pthread_mutex_destroy(&philo.mutex);
// 	return (0);
// }

//! Create multiple treads using loop 
// void	*ft_routine(void *arg)
// {
// 	t_philo *philo = (t_philo *)arg;
// 	int	i = 0;

// 	while (i < 1000000)
// 	{	
// 		pthread_mutex_lock(&philo->mutex);
// 		philo->score++;
// 		i++;
// 		pthread_mutex_unlock(&philo->mutex);
// 	}
// 	return (NULL);
// }

// void	ft_init_philo(t_philo *philo)
// {
// 	pthread_mutex_init(&philo->mutex, NULL);
// 	philo->score = 0;
// }

// int	main()
// {
// 	t_philo		philo;
// 	pthread_t	threads[THREADS];
// 	int			i = 0;

// 	ft_init_philo(&philo);
// 	// Create threads
// 	while (i < THREADS)
// 	{	
// 		if (pthread_create(&threads[i], NULL, &ft_routine, &philo) != 0)
// 			return (EXIT_FAILURE);
// 		printf("Thread Started Execution\n");
// 		i++;
// 	}
// 	// Join thrades
// 	i = 0;
// 	while (i < THREADS)
// 	{
// 		if (pthread_join(threads[i], NULL) != 0)
// 			return (EXIT_FAILURE);
// 		printf("Thread Finished Execution\n");
// 		i++;
// 	}
// 	printf("Score: %d\n", philo.score);
// 	pthread_mutex_destroy(&philo.mutex);
// 	return (0);
// }
