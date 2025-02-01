/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:42:51 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/01 19:17:06 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"





void	ft_draw_fractol(t_fractol *fractol)
{
	for (int y = 0; y < fractol->height; y++)
	{
		for (int x = 0; x < fractol->width; x++)
		{
			t_complex c = ft_map_pixel_to_complex(x, y, fractol);
			// ft_mandelbrot_set(fractol, c, x, y, fractol->precision);
			ft_julia_set(fractol, c, x, y, fractol->precision);
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
	fractol.width = 1000;
	fractol.height = 800;
	fractol.win = mlx_new_window(fractol.mlx, fractol.width, fractol.height, "Minilbx");
	if (NULL == fractol.mlx)
	{
		free(fractol.mlx);
		return (EXIT_FAILURE);
	}
	fractol.img.img_ptr = NULL;
	ft_init_complex_plane(&fractol);
	fractol.zoom = 1.0;
	fractol.offset_x = 0.0;
	fractol.offset_y = 0.0;
	fractol.precision = 50;
	fractol.julia_c_real = -0.7;
	fractol.julia_c_imag = 0.27015; 
	ft_generate_random_gradient_color(&fractol);

	// Init Img 
	ft_init_image_buffer(&fractol);
	
	ft_draw_fractol(&fractol);
	
	mlx_put_image_to_window(fractol.mlx,  fractol.win, fractol.img.img_ptr, 0, 0);
	mlx_destroy_image(fractol.mlx, fractol.img.img_ptr);

	// Lisening for mouse events
	mlx_mouse_hook(fractol.win, ft_mouse_event, &fractol);
	mlx_key_hook(fractol.win, ft_key_hook, &fractol);
	mlx_loop(fractol.mlx);

	// Clean Up
	mlx_destroy_window(fractol.mlx, fractol.win);
	mlx_destroy_display(fractol.mlx);
	free(fractol.mlx);
}
