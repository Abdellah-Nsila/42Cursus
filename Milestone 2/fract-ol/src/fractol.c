/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:18:14 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/05 13:24:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// void	ft_draw_fractal(t_fractol *fractol)
// {
// 	int			x, y;
// 	t_complex	c;

// 	ft_init_image_buffer(fractol); // Reset buffer at the start
// 	for (x = 0; x < fractol->width; x++)
// 	{
// 		for (y = 0; y < fractol->height; y++)
// 		{
// 			c = ft_map_to_complex(fractol, x, y);
// 			if (fractol->set_type == MANDELBROT_SQ)
// 				ft_mandelbrot_sq_set(fractol, c, x, y);
// 			else if (fractol->set_type == MANDELBROT_CUB)
// 				ft_mandelbrot_cub_set(fractol, c, x, y);
// 			else if (fractol->set_type == JULIA_SQ)
// 				ft_julia_sq_set(fractol, c, x, y);
// 			else if (fractol->set_type == JULIA_CUB)
// 				ft_julia_cub_set(fractol, c, x, y);
// 			else if (fractol->set_type == BURNINGSHIP_SQ)
// 				ft_burningship_sq_set(fractol, c, x, y);
// 			else if (fractol->set_type == BURNINGSHIP_CUB)
// 				ft_burningship_cub_set(fractol, c, x, y);
// 			else if (fractol->set_type == MANDELBOX)
// 				ft_mandelbox_set(fractol, c, x, y);
// 		}
// 	}
// 	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0, 0);
// }


void	ft_draw_fractal(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	c;

	ft_init_image_buffer(fractol);
	x = 0;
	while (x < fractol->width)
	{
		y = 0;
		while (y < fractol->height)
		{
			c = ft_map_to_complex(fractol, x, y);
			// ft_mandelbrot_sq_set(fractol, c, x, y);
			ft_mandelbrot_cub_set(fractol, c, x, y);
			// ft_julia_sq_set(fractol, c, x, y);
			// ft_julia_cub_set(fractol, c, x, y);
			// ft_burningship_sq_set(fractol, c, x, y);
			// ft_burningship_cub_set(fractol, c, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0, 0);
}

// TODO add Other set ... fix norm, coloring ,shadow, 
int	main(int ac, char **av)
{
	t_fractol	fractol;

	ft_check_parse(&fractol, ac, av);
	ft_init_fractol(&fractol);
	ft_init_complex_plan(&fractol);

	ft_init_image_buffer(&fractol);
	ft_draw_fractal(&fractol);

	mlx_hook(fractol.win, 6, 1L<<6, ft_mouse_move_hook, &fractol);
	mlx_mouse_hook(fractol.win, ft_mouse_hook, &fractol);
	mlx_key_hook(fractol.win, ft_key_hook, &fractol);
	mlx_loop_hook(fractol.mlx, ft_loop_hook, &fractol);
	mlx_loop(fractol.mlx);

	ft_clean_fractol(&fractol);
	ft_printf("Programme exit successfuly\n");
	exit(EXIT_SUCCESS);
}
