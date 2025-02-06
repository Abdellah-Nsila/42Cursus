/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:18:14 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/06 11:23:42 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_walk(t_fractol *fractol, int (*fractal_func)(t_fractol *, t_complex))
{
	int			x;
	int			y;
	t_complex	c;
	int			offset;

	ft_init_image_buffer(fractol);
	x = 0;
	while (x < fractol->width)
	{
		y = 0;
		while (y < fractol->height)
		{
			c = ft_map_to_complex(fractol, x, y);
			// ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, fractal_func(fractol, c));
			// Draw pixel directly to image buffer
            offset = (y * fractol->img.line_length) + (x * (fractol->img.bits_per_pixel / 8));
            *(unsigned int *)(fractol->img.img_pixels_ptr + offset) = fractal_func(fractol, c);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0, 0);
}

void	ft_draw_fractal(t_fractol *fractol)
{
	if (fractol->set_type == Mandelbrot_square)
		ft_walk(fractol, &ft_mandelbrot_sq_set);
	else if (fractol->set_type == Mandelbrot_cube)
		ft_walk(fractol, &ft_mandelbrot_cub_set);
	else if (fractol->set_type == Julia_square)
		ft_walk(fractol, &ft_julia_sq_set);
	else if (fractol->set_type == Julia_cube)
		ft_walk(fractol, &ft_julia_cub_set);
	else if (fractol->set_type == Burningship_square)
		ft_walk(fractol, &ft_burningship_sq_set);
	else if (fractol->set_type == Burningship_cube)
		ft_walk(fractol, &ft_burningship_cub_set);
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

// int	main(int ac, char **av)
// {
// 	char	*endptr;
// 	if (ac != 3)
// 		exit(EXIT_FAILURE);
// 	printf("x: %f\n", ft_strtod(av[1], &endptr));
// 	printf("y: %f\n", ft_strtod(av[2], &endptr));
// 	exit(EXIT_SUCCESS);
// }
