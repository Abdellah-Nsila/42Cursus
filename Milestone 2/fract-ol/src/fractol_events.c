/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:57:35 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/05 11:57:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_loop_hook(t_fractol *fractol)
{
	if (!fractol)
		return (1);
	ft_draw_fractal(fractol);
	return (0);
}

int	ft_mouse_move_hook(int x, int y, void *param)
{
	t_fractol	*fractol;
	
	fractol = param;
	if (fractol->trick_mouse)
	{	
		fractol->fixed_c_re = (double)x / fractol->width * 2.0 - 1.0;
		fractol->fixed_c_img = (double)y / fractol->height * 2.0 - 1.0;
	}
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (button == 4)
	{
		fractol->zoom *= 1.08;
		ft_zoom_plan(fractol, 1.08, x, y, ZOOM_IN);
		// ft_draw_fractal(fractol);
	}
	else if (button == 5)
	{
		fractol->zoom /= 1.08;
		ft_zoom_plan(fractol, 1 / 1.08, x, y, ZOOM_OUT);
		// ft_draw_fractal(fractol);
	}
	return (EXIT_SUCCESS);
}

int	ft_key_hook(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (keycode == ESCAPE)
	{
		ft_clean_fractol(fractol);
		ft_printf("Programme exit successfuly\n");
		exit(EXIT_SUCCESS);
	}
	else if (keycode == q)
		fractol->precision += 2;
	else if (keycode == w)
		fractol->precision -= 2;
	else if (keycode == a)
		fractol->smoth += 0.1;
	else if (keycode == s)
		fractol->smoth -= 0.1;
	else if (keycode == LEFT)
		ft_move_plan(fractol, -0.1 / fractol->zoom, 0);
	else if (keycode == RIGHT)
		ft_move_plan(fractol, 0.1 / fractol->zoom, 0);
	else if (keycode == UP)
		ft_move_plan(fractol, 0, 0.1 / fractol->zoom);
	else if (keycode == DOWN)
		ft_move_plan(fractol, 0, -0.1 / fractol->zoom);
	else if (keycode == o)
		fractol->color += 0.1;
	else if (keycode == p)
		fractol->color -= 0.1;
	else if (keycode == t)
	{
		if (fractol->trick_mouse)	
			fractol->trick_mouse = false;
		else
			fractol->trick_mouse = true;
	}
	// ft_draw_fractal(fractol);
	return (EXIT_SUCCESS);
}
