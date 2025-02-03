/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:47:38 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/03 10:56:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit(EXIT_FAILURE);
	fractol->width = 800;
	fractol->height = 600;
	fractol->win = mlx_new_window(fractol->mlx, fractol->width,
			fractol->height, "Fract-ol");
	if (!fractol->win)
	{
		ft_clean_fractol(fractol);
		exit(EXIT_FAILURE);
	}
}

void	ft_clean_fractol(t_fractol *fractol)
{
	if (fractol->win)
		mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
}
