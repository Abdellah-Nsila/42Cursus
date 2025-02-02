/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:42:51 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/02 12:23:02 by abnsila          ###   ########.fr       */
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
			if (fractol->set == Mandelbrot_sqrt)
				ft_mandelbrot_sq_set(fractol, c, x, y, fractol->precision);
			else if (fractol->set == Julia_sqrt)
				ft_julia_sq_set(fractol, c, x, y, fractol->precision);
			else if (fractol->set == Mandelbrot_cube)
				ft_mandelbrot_cub_set(fractol, c, x, y, fractol->precision);
			else if (fractol->set == Julia_cube)
				ft_julia_cub_set(fractol, c, x, y, fractol->precision);
		}
	}
}

void	ft_init_fractol(t_fractol *fractol)
{
	// Initiale mlx connection with (X/Server) && create window
	fractol->mlx = mlx_init();
	if (NULL == fractol->mlx)
		exit(EXIT_FAILURE);
	fractol->width = 1000;
	fractol->height = 800;
	fractol->win = mlx_new_window(fractol->mlx, fractol->width, fractol->height, "Minilbx");
	if (NULL == fractol->mlx)
	{
		free(fractol->mlx);
		exit(EXIT_FAILURE);
	}
	fractol->img.img_ptr = NULL;
	ft_init_image_buffer(fractol);
	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->precision = 50;
	fractol->julia_c_real = -0.8;
	fractol->julia_c_imag = 0.1; 
	ft_generate_random_gradient_color(fractol);
	ft_init_complex_plane(fractol);
}

void	ft_check_parse(t_fractol *fractol, int ac, char **av)
{
	if (ac == 2)
	{	
		if (ft_strlcmp("Mandelbrot", av[1], ft_strlen(av[1])) == true)
			fractol->set = Mandelbrot_sqrt;
		else if (ft_strlcmp("Julia", av[1], ft_strlen(av[1])) == true)
			fractol->set = Julia_sqrt;
	}
	else if (ac == 3)
	{
		if ((ft_strlcmp("Mandelbrot", av[1], ft_strlen(av[1])) == true)
			&& (ft_strlcmp("cube", av[2], ft_strlen(av[2])) == true))
			fractol->set = Mandelbrot_cube;
		else if ((ft_strlcmp("Julia", av[1], ft_strlen(av[1])) == true)
			&& (ft_strlcmp("cube", av[2], ft_strlen(av[2])) == true))
			fractol->set = Julia_cube;
	}
	else
	{
		ft_printf("Usage: ./fratcol <set> type\n\
	[1] ./fratcol Mandelbrot\n\
	[2] ./fratcol Julia\n");
		exit(EXIT_FAILURE);
	}
}

int main(int ac, char **av)
{
	t_fractol	fractol;

	ft_check_parse(&fractol, ac, av);
	ft_init_fractol(&fractol);
	ft_draw_fractol(&fractol);
	
	mlx_put_image_to_window(fractol.mlx,  fractol.win, fractol.img.img_ptr, 0, 0);
	mlx_destroy_image(fractol.mlx, fractol.img.img_ptr);

	// Lisening for events
	mlx_mouse_hook(fractol.win, ft_mouse_event, &fractol);
	mlx_key_hook(fractol.win, ft_key_hook, &fractol);
	mlx_loop(fractol.mlx);

	// Clean Up
	mlx_destroy_window(fractol.mlx, fractol.win);
	mlx_destroy_display(fractol.mlx);
	free(fractol.mlx);
}
