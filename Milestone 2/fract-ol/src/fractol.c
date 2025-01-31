/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:42:51 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/31 19:04:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbrot_set(t_fractol *fractol, t_complex c, int x, int y, int max_iter)
{
	t_complex z = {0, 0};
	int iter = 0;
	t_bool isInside = true;

	while (iter < max_iter)
	{
		double z_real_sq = z.real * z.real;
		double z_imag_sq = z.imag * z.imag;

		if (z_real_sq + z_imag_sq > 4.0) // Escape condition
		{
			isInside = false;
			break;
		}
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = z_real_sq - z_imag_sq + c.real;
		iter++;
	}
	if(isInside)
		ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
	else
	{
		int color = ft_get_color(fractol, iter, fractol->precision);
		ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, color);
	}
}

void	ft_draw_fractol(t_fractol *fractol)
{
	for (int y = 0; y < fractol->height; y++)
	{
		for (int x = 0; x < fractol->width; x++)
		{
			t_complex c = ft_map_pixel_to_complex(x, y, fractol);
			ft_mandelbrot_set(fractol, c, x, y, fractol->precision);
		}
	}
}

int main()
{
	t_fractol	fractol;

	// Initiale mlx connection with (X/Server) && create window
	fractol.mlx = mlx_init();
	if (NULL == fractol.mlx)
		return (EXIT_FAILURE);
	fractol.width = 800;
	fractol.height = 600;
	fractol.win = mlx_new_window(fractol.mlx, fractol.width, fractol.height, "Minilbx");
	if (NULL == fractol.mlx)
	{
		free(fractol.mlx);
		return (EXIT_FAILURE);
	}
	ft_init_complex_plane(&fractol);
	fractol.zoom = 1.0;
	fractol.offset_x = 0.0;
	fractol.offset_y = 0.0;
	fractol.precision = 50;
	ft_generate_random_gradient_color(&fractol);

	// Init Img 
	fractol.img.img_ptr = mlx_new_image(fractol.mlx, fractol.width, fractol.height);
	fractol.img.img_pixels_ptr = mlx_get_data_addr(fractol.img.img_ptr, &fractol.img.bits_per_pixel, &fractol.img.line_length,
								&fractol.img.endian);
	
	ft_draw_fractol(&fractol);
	
	mlx_put_image_to_window(fractol.mlx,  fractol.win, fractol.img.img_ptr, 0, 0);
	// mlx_destroy_image(fractol.mlx, fractol.img.img_ptr);

	// Lisening for mouse events
	mlx_mouse_hook(fractol.win, ft_mouse_event, &fractol);
	mlx_key_hook(fractol.win, ft_key_hook, &fractol);
	mlx_loop(fractol.mlx);

	// Clean Up
	mlx_destroy_window(fractol.mlx, fractol.win);
	mlx_destroy_display(fractol.mlx);
	free(fractol.mlx);
}
