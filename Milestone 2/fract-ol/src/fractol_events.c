/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:57:35 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/03 19:10:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (button == 1)
	{	
		ft_draw_fractal(fractol);
	}
	if (button == 4)
	{
		ft_zoom_plan(fractol, 1.1, x, y);
		ft_draw_fractal(fractol);
	}
	else if (button == 5)
	{
		ft_zoom_plan(fractol, 0.9, x, y);
		ft_draw_fractal(fractol);
	}
	return (EXIT_SUCCESS);
}

int	ft_key_hook(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (keycode == XK_Escape)
	{
		ft_clean_fractol(fractol);
		ft_printf("Programme exit successfuly\n");
		exit(EXIT_SUCCESS);
	}
	else if (keycode == XK_q)
		fractol->precision += 2;
	else if (keycode == XK_w)
		fractol->precision -= 2;
	ft_draw_fractal(fractol);
	return (EXIT_SUCCESS);
}
