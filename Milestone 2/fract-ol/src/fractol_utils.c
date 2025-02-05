/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:37:37 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/05 11:22:58 by abnsila          ###   ########.fr       */
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

void	ft_put_escape_pixel(t_fractol *fractol, int iter, int x, int y)
{
	int color;

	color = ft_create_psychedelic_color(fractol, iter);
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, color);
}

int	ft_create_psychedelic_color(t_fractol *fractol, int iter)
{
	// int r = (int)(sin(0.1 * (double)iter + fractol->color) * 127 + 128);
	// int g = (int)(sin(0.1 * (double)iter + fractol->color + 2.0) * 127 + 128);
	// int b = (int)(sin(0.1 * (double)iter + fractol->color + 4.0) * 127 + 128);

	int r = (int)(sin(fractol->smoth * (double)iter + fractol->color) * 127 + 128);
	int g = (int)(sin(fractol->smoth * (double)iter + fractol->color + 2.0) * 127 + 128);
	int b = (int)(sin(fractol->smoth * (double)iter + fractol->color + 4.0) * 127 + 128);
	return (r << 16) | (g << 8) | b;
}
