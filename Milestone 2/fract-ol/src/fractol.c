/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:18:14 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/04 16:56:09 by abnsila          ###   ########.fr       */
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
			ft_mandelbrot_sq_set(fractol, c, x, y);
			// ft_mandelbrot_cub_set(fractol, c, x, y);
			// ft_julia_sq_set(fractol, c, x, y);
			// ft_julia_cub_set(fractol, c, x, y);
			// ft_burningship_sq_set(fractol, c, x, y);
			// ft_burningship_cub_set(fractol, c, x, y);
			// ft_mandelbox_set(fractol, c, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0, 0);
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

// TODO add Other set ... fix norm, coloring ,shadow, 
int	main(void)
{
	t_fractol	fractol;

	ft_init_fractol(&fractol);
	ft_init_complex_plan(&fractol);

	ft_draw_fractal(&fractol);

	mlx_mouse_hook(fractol.win, ft_mouse_hook, &fractol);
	mlx_hook(fractol.win, 6, 1L<<6, ft_mouse_move_hook, &fractol);
	mlx_key_hook(fractol.win, ft_key_hook, &fractol);
	mlx_loop_hook(fractol.mlx, ft_loop_hook, &fractol);
	mlx_loop(fractol.mlx);

	ft_clean_fractol(&fractol);
	ft_printf("Programme exit successfuly\n");
	exit(EXIT_SUCCESS);
}
