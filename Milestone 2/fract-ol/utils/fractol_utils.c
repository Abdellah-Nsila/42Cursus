/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:54:47 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/31 12:38:48 by abnsila          ###   ########.fr       */
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

void	ft_clear_image(t_mlx_data *mlx_data)
{
	// Fill the image buffer with black (or any other color)
	int total_pixels = mlx_data->width * mlx_data->height;
	for (int i = 0; i < total_pixels; i++)
	{
		((int *)mlx_data->img.img_pixels_ptr)[i] = 0x000000; // Black color
	}
}