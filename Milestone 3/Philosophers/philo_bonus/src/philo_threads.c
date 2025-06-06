/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:46:13 by abnsila           #+#    #+#             */
/*   Updated: 2025/04/14 15:33:33 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_exit(t_data *data, t_philo *philo)
{
	if (philo && data)
	{
		ft_wait_thread(philo->self_monitor);
		ft_wait_thread(philo->global_monitor);
	}
	ft_destroy_sem(data);
	ft_free_sem(&philo->done_sem, true);
	ft_free_sem(&philo->meal_sem, true);
	exit(EXIT_SUCCESS);
}

void	ft_child_process(t_data *data, int id)
{
	t_philo	philo;

	ft_bzero(&philo, sizeof(t_philo));
	philo.id = id;
	philo.data = data;
	philo.meals_eaten = 0;
	ft_create_psem(&philo.done_sem, 1, id, PHILO_DONE_SEM);
	ft_create_psem(&philo.meal_sem, 1, id, PHILO_MEAL_SEM);
	philo.last_meal_time = data->global_start_time;
	if (pthread_create(&(philo.self_monitor), NULL,
			&ft_self_monitor, &philo) != 0)
		ft_philo_exit(data, &philo);
	if (pthread_create(&(philo.global_monitor), NULL,
			&ft_global_monitor, &philo) != 0)
		ft_philo_exit(data, &philo);
	ft_start_simulation(data, &philo);
	ft_philo_exit(data, &philo);
}
