/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:18:14 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/03 19:16:44 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


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
			// ft_mandelbrot_cub_set(fractol, c, x, y);
			// ft_julia_sq_set(fractol, c, x, y);
			ft_julia_cub_set(fractol, c, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0, 0);
}

// TODO add Burninship 
int	main(void)
{
	t_fractol	fractol;

	ft_init_fractol(&fractol);
	ft_init_complex_plan(&fractol);

	//TODO Pls use buffer image to reset the old zoom edges
	ft_draw_fractal(&fractol);

	mlx_mouse_hook(fractol.win, ft_mouse_hook, &fractol);
	mlx_key_hook(fractol.win, ft_key_hook, &fractol);
	mlx_loop(fractol.mlx);

	ft_clean_fractol(&fractol);
	ft_printf("Programme exit successfuly\n");
	exit(EXIT_SUCCESS);
}
