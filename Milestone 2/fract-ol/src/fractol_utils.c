/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:37:37 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/06 13:45:52 by abnsila          ###   ########.fr       */
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

int	ft_get_psychedelic_color(t_fractol *fractol, int iter)
{
	if (!fractol)
		return (1);
	return ((fractol->end_color - fractol->start_color) * iter / DEFAULT_ITERATIONS + fractol->start_color);
}

void	ft_generate_limits_color(t_fractol *fractol)
{
	fractol->start_color = rand() % 0xFFFFFF;
	fractol->end_color = rand() % fractol->start_color;
}
