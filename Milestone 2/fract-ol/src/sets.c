/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:16:57 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/01 19:19:01 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//! Mandelbrot z^2 + c
void	ft_mandelbrot_sq_set(t_fractol *fractol, t_complex c, int x, int y, int max_iter)
{
	t_complex z = {0, 0};
	int iter = 0;
	t_bool isInside = true;

	while (iter < max_iter)
	{
		double z_real_sq = z.real * z.real;
		double z_imag_sq = z.imag * z.imag;

		if (z_real_sq + z_imag_sq > 4.0) // Escape condition
		{
			isInside = false;
			break;
		}
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = z_real_sq - z_imag_sq + c.real;
		iter++;
	}
	if(isInside)
		ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
	else
	{
		int color = ft_get_color(fractol, iter, fractol->precision);
		ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, color);
	}
}

//! Mandelbrot z^3 + c
void	ft_mandelbrot_cub_set(t_fractol *fractol, t_complex c, int x, int y, int max_iter)
{
	t_complex z = {0, 0};
	int iter = 0;
	t_bool isInside = true;

	while (iter < max_iter)
	{
		double z_real_sq = z.real * z.real;
		double z_imag_sq = z.imag * z.imag;

		if ((z_real_sq + z_imag_sq) > 4.0) // Escape condition
		{
			isInside = false;
			break;
		}
		z.real = (z_real_sq * z.real) - (3 * z.real * z_imag_sq) + c.real;
		z.imag = (3 * z_real_sq * z.imag) - (z_imag_sq * z.imag) + c.imag;
		iter++;
	}
	if(isInside)
		ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
	else
	{
		int color = ft_get_color(fractol, iter, fractol->precision);
		ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, color);
	}
}

//! Julia  z^2 + c
void	ft_julia_sq_set(t_fractol *fractol, t_complex c, int x, int y, int max_iter)
{
	int iter = 0;
	t_bool isInside = true;

	while (iter < max_iter)
	{
		double z_real = c.real;
		double z_imag = c.imag;

		// Escape condition: If |z| > 2, it escapes
		if ((z_real * z_real) + (z_imag * z_imag) > 4.0)
		{
			isInside = false;
			break;
		}

		// Julia formula: z = z^2 + c (Fixed `c`)
		double temp = (z_real * z_real) - (z_imag * z_imag) + fractol->julia_c_real;
		c.imag = (2 * z_real * z_imag) + fractol->julia_c_imag;
		c.real = temp;

		iter++;
	}

	if (isInside)
		ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000); // Black inside set
	else
	{
		int color = ft_get_color(fractol, iter, fractol->precision);
		ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, color);
	}
}

//! Julia z^3 + c
void	ft_julia_cub_set(t_fractol *fractol, t_complex c, int x, int y, int max_iter)
{
	int iter = 0;
	t_bool isInside = true;

	while (iter < max_iter)
	{
		double z_real = c.real;
		double z_imag = c.imag;

		// Escape condition: If |z| > 2, it escapes
		if ((z_real * z_real) + (z_imag * z_imag) > 4.0)
		{
			isInside = false;
			break;
		}

		// Julia formula: z = z^3 + c (Fixed `c`)
		double temp = (z_real * z_real * z_real) - (3 * z_real * (z_imag * z_imag)) + fractol->julia_c_real;
		c.imag = (3 * (z_real * z_real) * z_imag) - (z_imag * z_imag * z_imag) + fractol->julia_c_imag;
		
		c.real = temp;

		iter++;
	}

	if (isInside)
		ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000); // Black inside set
	else
	{
		int color = ft_get_color(fractol, iter, fractol->precision);
		ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, color);
	}
}
