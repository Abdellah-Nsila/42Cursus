/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:57:35 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/04 15:23:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_loop_hook(t_fractol *fractol)
{
	if (!fractol)
		return (1);
	ft_render_fractal(fractol);
	return (0);
}

int	ft_mouse_move_hook(int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	fractol->fixed_c_re = (double)x / fractol->width * 2.0 - 1.0;
	fractol->fixed_c_img = (double)y / fractol->height * 2.0 - 1.0;

	return (0);
}

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (button == 1)
	{
		fractol->zoom_target_x = x;
		fractol->zoom_target_y = y;
		fractol->zoom_active = true;
	}
	else if (button == 3)
		fractol->zoom_active = false;
	else if (button == 4)
	{
		fractol->zoom *= 1.1;
		ft_zoom_plan(fractol, 1.1, x, y);
	}
	else if (button == 5)
	{
		fractol->zoom_active = false;
		fractol->zoom /= 1.1;
		ft_zoom_plan(fractol, 1 / 1.1, x, y);
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
	else if (keycode == XK_b)
		fractol->scale += 0.01;
	else if (keycode == XK_v)
		fractol->scale -= 0.01;
	else if (keycode == XK_w)
		fractol->precision -= 2;
	else if (keycode == XK_Left)
		ft_move_plan(fractol, -0.1 / fractol->zoom, 0);
	else if (keycode == XK_Right)
		ft_move_plan(fractol, 0.1 / fractol->zoom, 0);
	else if (keycode == XK_Up)
		ft_move_plan(fractol, 0, 0.1 / fractol->zoom);
	else if (keycode == XK_Down)
		ft_move_plan(fractol, 0, -0.1 / fractol->zoom);
	else if (keycode == XK_p)
		fractol->color += 0.1;
	else if (keycode == XK_o)
		fractol->color -= 0.1;
	// ft_draw_fractal(fractol);
	return (EXIT_SUCCESS);
}
