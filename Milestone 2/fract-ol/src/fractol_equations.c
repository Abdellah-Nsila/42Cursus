/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:54:11 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/04 16:21:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_put_escape_pixel(t_fractol *fractol, int iter, int x, int y)
{
	int color;

	color = ft_create_psychedelic_color(fractol, iter);
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, color);
}

void	ft_mandelbrot_sq_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	int			iter;
	
	iter = 0;
	z.re = 0;
	z.img = 0;
	while (iter < fractol->precision)
	{
		if ((z.re * z.re) + (z.img * z.img) > 4.0)
			return(ft_put_escape_pixel(fractol, iter, x, y), NULL);
		z.img = 2 * z.re * z.img + c.img;
		z.re = (z.re * z.re) - (z.img * z.img) + c.re;
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void	ft_mandelbrot_cub_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	int			iter;
	
	iter = 0;
	z.re = 0;
	z.img = 0;
	while (iter < (int)fractol->precision)
	{
		if ((z.re * z.re) + (z.img * z.img) > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);
		z.re = (z.re * z.re * z.re) - (3 * z.re * (z.img * z.img)) + c.re;
		z.img = (3 * (z.re * z.re) * z.img) - (z.img * z.img * z.img) + c.img;
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void	ft_julia_sq_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	double		temp;
	int			iter;
	
	iter = 0;
	z.re = c.re;
	z.img = c.img;
	while (iter < (int)fractol->precision)
	{
		if ((z.re * z.re) + (z.img * z.img) > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);
		temp = (z.re * z.re) - (z.img * z.img) + fractol->fixed_c_re;
		z.img = (2 * z.re * z.img) + fractol->fixed_c_img;
		z.re = temp;
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void	ft_julia_cub_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	double		temp;
	int			iter;
	
	iter = 0;
	z.re = c.re;
	z.img = c.img;
	while (iter < (int)fractol->precision)
	{
		if ((z.re * z.re) + (z.img * z.img) > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);
		temp = (z.re * z.re * z.re) - (3 * z.re * (z.img * z.img)) + fractol->fixed_c_re;
		z.img = (3 * (z.re * z.re) * z.img) - (z.img * z.img * z.img) + fractol->fixed_c_img;
		z.re = temp;
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void	ft_burningship_sq_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	int			iter;
	
	iter = 0;
	z.re = c.re;
	z.img = c.img;
	while (iter < fractol->precision)
	{
		if ((z.re * z.re) + (z.img * z.img) > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);
		z.img = fabs(2 * z.re * z.img) - c.img;
		z.re = fabs((z.re * z.re) - (z.img * z.img) - c.re);
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void	ft_burningship_cub_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	int			iter;
	
	iter = 0;
	z.re = c.re;
	z.img = c.img;
	while (iter < fractol->precision)
	{
		if ((z.re * z.re) + (z.img * z.img) > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);

		z.re = fabs((z.re * z.re * z.re) - (3 * z.re * (z.img * z.img)) - c.re);
		z.img = fabs(3 * z.re * z.re * z.img) - fabs(z.img * z.img * z.img) - c.img;
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void ft_box_fold(t_complex *z)
{
	if (z->re > 1.0)
		z->re = 2.0 - z->re;
	else if (z->re < -1.0)
		z->re = -2.0 - z->re;
	if (z->img > 1.0)
		z->img = 2.0 - z->img;
	else if (z->img < -1.0)
		z->img = -2.0 - z->img;
}

void	ft_mandelbox_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	int			iter;
	
	iter = 0;
	z.re = c.re;
	z.img = c.img;
	while (iter < fractol->precision)
	{
		ft_box_fold(&z);
		z.re = fractol->scale * z.re + c.re;
		z.img = fractol->scale * z.img + c.img;
		if (((z.re * z.re) + (z.img * z.img)) > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}
