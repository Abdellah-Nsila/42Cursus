/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:54:47 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/31 15:43:13 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_my_optimized_pixel_put(t_mlx_data *mlx_data, t_img *img, int x, int y, int color)
{
	int	offset;
	if (x >= 0 && x < mlx_data->width && y >= 0 && y < mlx_data->height)
	{
		offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
		*(unsigned int *)(img->img_pixels_ptr + offset) = color;
	}
}

void	ft_clear_image(t_mlx_data *mlx_data, int color)
{
	// Fill the image buffer with black (or any other color)
	int total_pixels = mlx_data->width * mlx_data->height;
	for (int i = 0; i < total_pixels; i++)
	{
		((int *)mlx_data->img.img_pixels_ptr)[i] = color; // Black color
	}
}

int	ft_get_color(t_mlx_data *mlx_data, int iteration, int max_iterations)
{
	// Define two colors for the gradient
	// int color1 = 0x0000FF; // Blue
	// int color2 = 0xFF0000; // Red
	int color1 = mlx_data->color1;
	int color2 = mlx_data->color2;

	// Normalize the iteration count to a value between 0 and 1
	double t = (double)iteration / max_iterations;

	// Interpolate between the two colors
	int r = (int)(((color2 >> 16) & 0xFF) * t + ((color1 >> 16) & 0xFF) * (1 - t));
	int g = (int)(((color2 >> 8) & 0xFF) * t + ((color1 >> 8) & 0xFF) * (1 - t));
	int b = (int)((color2 & 0xFF) * t + (color1 & 0xFF) * (1 - t));

	// Combine the RGB components into a single color value
	return (r << 16) | (g << 8) | b;
}

void	ft_generate_random_gradient_color(t_mlx_data *mlx_data)
{
	mlx_data->color1 = rand() * 1000000;
	mlx_data->color2 = rand() * 1000000;
}
