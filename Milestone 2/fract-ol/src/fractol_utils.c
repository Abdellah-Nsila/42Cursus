/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:37:37 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/03 19:06:59 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_my_optimized_pixel_put(t_fractol *fractol, t_img *img, int x, int y, int color)
{
	int	offset;
	if (x >= 0 && x < fractol->width && y >= 0 && y < fractol->height)
	{
		offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
		*(unsigned int *)(img->img_pixels_ptr + offset) = color;
	}
}

int create_gradient_color(int iter, int max_iter)
{
	// Normalize the iteration count to a value between 0 and 255
	int t = (iter * 255) / max_iter;

	// Define color transitions
	int r, g, b;

	if (t < 85) // Black to blue
	{
		r = 0;
		g = 0;
		b = t * 3;
	}
	else if (t < 170) // Blue to green
	{
		r = 0;
		g = (t - 85) * 3;
		b = 255 - (t - 85) * 3;
	}
	else // Green to red
	{
		r = (t - 170) * 3;
		g = 255 - (t - 170) * 3;
		b = 0;
	}

	// Combine RGB components into a single color value
	return (r << 16) | (g << 8) | b;
}

int	create_psychedelic_color(int iter)
{
	// Use sine and cosine functions to create oscillating color patterns
	int r = (int)(sin(iter * 0.1) * 127 + 128);
	int g = (int)(sin(iter * 0.2) * 127 + 128);
	int b = (int)(sin(iter * 0.3) * 127 + 128);

	// Combine RGB components into a single color value
	return (r << 16) | (g << 8) | b;
}

int create_combined_color(int iter, int max_iter)
{
	// Base gradient color
	int base_color = create_gradient_color(iter, max_iter);

	// Psychedelic modulation
	int r = (base_color >> 16) & 0xFF;
	int g = (base_color >> 8) & 0xFF;
	int b = base_color & 0xFF;

	r = (int)(r * (sin(iter * 0.1) * 0.5 + 0.5));
	g = (int)(g * (sin(iter * 0.2) * 0.5 + 0.5));
	b = (int)(b * (sin(iter * 0.3) * 0.5 + 0.5));

	// Combine RGB components into a single color value
	return (r << 16) | (g << 8) | b;
}
