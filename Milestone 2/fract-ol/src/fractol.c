/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:18:14 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/03 13:32:52 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_draw_square(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	c;
	
	x = 0;
	while (x < fractol->width)
	{
		y = 0;
		while (y < fractol->height)
		{
			c = ft_map_to_complex(fractol, x, y);
			// printf("re: %f   img: %f\n", c.re, c.img);
			if (c.re  >= -1.0 && c.re <= 1.0 && c.img >= -0.5 && c.img <= 0.5)
			{
				// ft_printf("x: %d   y: %d\n", x, y);
				mlx_pixel_put(fractol->mlx, fractol->win, x, y, 0xFF0000);
			}
			y++;
		}
		x++;
	}
}

int	main(void)
{
	t_fractol	fractol;

	ft_init_fractol(&fractol);
	ft_init_complex_plan(&fractol);

	ft_draw_square(&fractol);

	mlx_mouse_hook(fractol.win, ft_mouse_hook, &fractol);
	mlx_key_hook(fractol.win, ft_key_hook, &fractol);
	mlx_loop(fractol.mlx);

	ft_clean_fractol(&fractol);
	ft_printf("Programme exit successfuly\n");
	exit(EXIT_SUCCESS);
}
