/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:57:35 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/07 16:19:53 by abnsila          ###   ########.fr       */
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

int	ft_mouse_move_hook(int x, int y, t_fractol *fractol)
{
	if (fractol->trick_mouse == 1)
	{	
		fractol->fixed_c_re = (double)x / fractol->width * 2.0 - 1.0;
		fractol->fixed_c_img = (double)y / fractol->height * 2.0 - 1.0;
	}
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == ZOOM_IN)
	{
		fractol->zoom *= ZOOM_FACTOR;
		ft_zoom_plan(fractol, ZOOM_FACTOR, x, y, ZOOM_IN);
	}
	else if (button == ZOOM_OUT)
	{
		fractol->zoom /= ZOOM_FACTOR;
		ft_zoom_plan(fractol, 1 / ZOOM_FACTOR, x, y, ZOOM_OUT);
	}
	else if (button == INCREASE_BUTTON)
		fractol->precision += PRECISION_FACTOR;
	else if (button == DECREASE_BUTTON)
		fractol->precision -= PRECISION_FACTOR;
	return (EXIT_SUCCESS);
}

int	ft_key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == ESCAPE_KEY)
		ft_close(fractol);
	else if (keycode == LEFT_KEY)
		ft_move_plan(fractol, -MOVE_FACTOR / fractol->zoom, 0);
	else if (keycode == RIGHT_KEY)
		ft_move_plan(fractol, MOVE_FACTOR / fractol->zoom, 0);
	else if (keycode == UP_KEY)
		ft_move_plan(fractol, 0, MOVE_FACTOR / fractol->zoom);
	else if (keycode == DOWN_KEY)
		ft_move_plan(fractol, 0, -MOVE_FACTOR / fractol->zoom);
	else if (keycode == SHIFT_KEY)
		ft_generate_random_gradient_color(fractol);
		// ft_generate_limits_color(fractol);
	else if (keycode == SPACE_KEY)
		fractol->trick_mouse = 1 - (fractol->trick_mouse / 1);
	return (EXIT_SUCCESS);
}
