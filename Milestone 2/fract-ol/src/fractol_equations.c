/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:54:11 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/05 09:31:56 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbrot_sq_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	double		z_re_sq;
	double		z_img_sq;	
	int			iter;
	
	iter = 0;
	z.re = 0;
	z.img = 0;
	while (iter < fractol->precision)
	{
		z_re_sq = z.re * z.re;	
		z_img_sq = z.img * z.img;
		if (z_re_sq + z_img_sq > 4.0)
			return(ft_put_escape_pixel(fractol, iter, x, y), NULL);
		z.img = 2 * z.re * z.img + c.img;
		z.re = z_re_sq - z_img_sq + c.re;
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void	ft_mandelbrot_cub_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	double		z_re_sq;
	double		z_img_sq;
	int			iter;
	
	iter = 0;
	z.re = 0;
	z.img = 0;
	while (iter < (int)fractol->precision)
	{
		z_re_sq = z.re * z.re;	
		z_img_sq = z.img * z.img;
		if (z_re_sq + z_img_sq > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);
		z.re = (z_re_sq * z.re) - (3 * z.re * z_img_sq) + c.re;
		z.img = (3 * z_re_sq * z.img) - (z_img_sq  * z.img) + c.img;
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void	ft_julia_sq_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	double		z_re_sq;
	double		z_img_sq;
	double		temp;
	int			iter;
	
	iter = 0;
	z.re = c.re;
	z.img = c.img;
	while (iter < (int)fractol->precision)
	{
		z_re_sq = z.re * z.re;	
		z_img_sq = z.img * z.img;
		if (z_re_sq + z_img_sq > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);
		temp = z_re_sq - z_img_sq + fractol->fixed_c_re;
		z.img = (2 * z.re * z.img) + fractol->fixed_c_img;
		z.re = temp;
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void	ft_julia_cub_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	double		z_re_sq;
	double		z_img_sq;
	double		temp;
	int			iter;
	
	iter = 0;
	z.re = c.re;
	z.img = c.img;
	while (iter < (int)fractol->precision)
	{
		z_re_sq = z.re * z.re;	
		z_img_sq = z.img * z.img;
		if (z_re_sq + z_img_sq > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);
		temp = (z_re_sq * z.re) - (3 * z.re * z_img_sq ) + fractol->fixed_c_re;
		z.img = (3 * z_re_sq * z.img) - (z_img_sq * z.img) + fractol->fixed_c_img;
		z.re = temp;
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void	ft_burningship_sq_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	double		z_re_sq;
	double		z_img_sq;
	int			iter;
	
	iter = 0;
	z.re = c.re;
	z.img = c.img;
	while (iter < fractol->precision)
	{
		z_re_sq = z.re * z.re;	
		z_img_sq = z.img * z.img;
		if (z_re_sq + z_img_sq > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);
		z.img = fabs(2 * z.re * z.img) - c.img;
		z.re = fabs(z_re_sq - z_img_sq - c.re);
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}

void	ft_burningship_cub_set(t_fractol *fractol, t_complex c, int x, int y)
{
	t_complex	z;
	double		z_re_sq;
	double		z_img_sq;
	int			iter;
	
	iter = 0;
	z.re = c.re;
	z.img = c.img;
	while (iter < fractol->precision)
	{
		z_re_sq = z.re * z.re;	
		z_img_sq = z.img * z.img;
		if (z_re_sq + z_img_sq > 4.0)
			return (ft_put_escape_pixel(fractol, iter, x, y), NULL);

		z.re = fabs((z_re_sq * z.re) - (3 * z.re * z_img_sq) - c.re);
		z.img = fabs((3 * z_re_sq * z.img) - (z_img_sq * z.img) - c.img);
		iter++;
	}
	ft_my_optimized_pixel_put(fractol, &fractol->img, x, y, 0x000000);
}
