/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:48:15 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/12 17:40:08 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_routine()
{
	printf("A New Thread\n");
	sleep(3);
	printf("Ending of Thread\n");
	return (NULL);
}


int	main()
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &ft_routine, NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_create(&t2, NULL, &ft_routine, NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_join(t1, NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_join(t1, NULL) != 0)
		return (EXIT_FAILURE);
	return (0);
}
