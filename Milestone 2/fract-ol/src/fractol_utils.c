/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:37:37 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/04 15:50:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_abs(int nbr)
{
	return ((nbr) * ((nbr >= 0) * 2 - 1));
}

void	ft_my_optimized_pixel_put(t_fractol *fractol, t_img *img, int x, int y, int color)
{
	int	offset;
	if (x >= 0 && x < fractol->width && y >= 0 && y < fractol->height)
	{
		offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
		*(unsigned int *)(img->img_pixels_ptr + offset) = color;
	}
}

void	ft_render_fractal(t_fractol *fractol)
{
	if (fractol->zoom_active == true)
	{
		fractol->zoom *= 1.1;
		ft_zoom_plan(fractol, 1.1, fractol->zoom_target_x, fractol->zoom_target_y);
	}
	ft_draw_fractal(fractol);
}

int	ft_create_psychedelic_color(t_fractol *fractol, int iter)
{
	int r = (int)(sin(0.1 * (double)iter + fractol->color) * 127 + 128);
	int g = (int)(sin(0.1 * (double)iter + fractol->color + 2.0) * 127 + 128);
	int b = (int)(sin(0.1 * (double)iter + fractol->color + 4.0) * 127 + 128);
	return (r << 16) | (g << 8) | b;
}
