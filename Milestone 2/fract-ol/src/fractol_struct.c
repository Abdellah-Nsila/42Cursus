/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:47:38 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/06 13:45:44 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_fractol(t_fractol *fractol)
{
	srand(time(NULL));
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit(EXIT_FAILURE);
	// fractol->width = 1920;
	// fractol->height = 1080;
	fractol->width = 1280;
	fractol->height = 800;
	fractol->win = mlx_new_window(fractol->mlx, fractol->width,
			fractol->height, "Fract-ol");
	if (!fractol->win)
	{
		ft_clean_fractol(fractol);
		exit(EXIT_FAILURE);
	}
	fractol->zoom = 1.0;
	fractol->trick_mouse = false;
	fractol->img.img_ptr = NULL;
	fractol->precision = DEFAULT_ITERATIONS;
	// fractol->fixed_c_re = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Range: [-1, 1]
	// fractol->fixed_c_img = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Range: [-1, 1]
	fractol->color = (double)rand() / RAND_MAX * 2 * M_PI;
	ft_generate_limits_color(fractol);
}

void	ft_init_image_buffer(t_fractol *fractol)
{
	if (fractol->img.img_ptr)
		mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	fractol->img.img_ptr = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	fractol->img.img_pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bits_per_pixel, &fractol->img.line_length,
								&fractol->img.endian);
}

void	ft_clean_fractol(t_fractol *fractol)
{
	if (fractol->img.img_ptr)
		mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	if (fractol->win)
		mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
}
