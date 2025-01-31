/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:42:51 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/31 12:40:18 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_calculate_mandelbrot_set(t_mlx_data *mlx_data)
{

double			MinRe = -2.0;
double			MaxRe = 1.0;
double			MinIm = -1.2;
double			MaxIm = MinIm+(MaxRe-MinRe) * mlx_data->height / mlx_data->width;
double			Re_factor = (MaxRe-MinRe) / (mlx_data->width - 1);
double			Im_factor = (MaxIm-MinIm) / (mlx_data->height - 1);
// int				MaxIterations = mlx_data->precision;

for(int y = 0; y < mlx_data->height; ++y)
{
	double c_im = MaxIm - (y * Im_factor);
	for(int x = 0; x < mlx_data->width; ++x)
	{
		double c_re = MinRe + (x * Re_factor);

		double Z_re = c_re, Z_im = c_im;
		t_bool isInside = true;
		for(int n = 0; n < mlx_data->precision; ++n)
		{
			double Z_re2 = (Z_re * Z_re), Z_im2 = Z_im*Z_im;
			if(Z_re2 + Z_im2 > 4)
			{
				isInside = false;
				break;
			}
			Z_im = (2 * (Z_re * Z_im)) + c_im;
			Z_re = Z_re2 - Z_im2 + c_re;
		}
		if(isInside)
		{
			// mlx_pixel_put(mlx_data->mlx, mlx_data->win, x, y, 0xffffff);
			ft_my_optimized_pixel_put(mlx_data, &mlx_data->img, x, y, rand() * 1000000);
		}
	}
}
}

int mouse_event(int button, int x, int y, void *param)
{
    t_mlx_data *mlx_data;

    mlx_data = param;
    printf("Mouse Button: %d   x: %d  y: %d  precision: %d\n", button, x, y, mlx_data->precision);

    // Increase precision
    if (button == 4)
    {
        mlx_data->precision += 1;
    }
    // Decrease precision
    else if (button == 5)
    {
        mlx_data->precision -= 1;
    }

	// Clear the image buffer before redrawing
    ft_clear_image(mlx_data);

    // Recalculate the Mandelbrot set with the new precision
    ft_calculate_mandelbrot_set(mlx_data);

    // Redraw the image in the window
    mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.img_ptr, 0, 0);

    return (EXIT_SUCCESS);
}

int main()
{
	t_mlx_data	mlx_data;

	mlx_data.mlx = mlx_init();
	if (NULL == mlx_data.mlx)
		return (EXIT_FAILURE);
	mlx_data.width = 800;
	mlx_data.height = 600;
	mlx_data.win = mlx_new_window(mlx_data.mlx, mlx_data.width, mlx_data.height, "Minilbx");
	if (NULL == mlx_data.mlx)
	{
		free(mlx_data.mlx);
		return (EXIT_FAILURE);
	}

	// Init Img 
	mlx_data.img.img_ptr = mlx_new_image(mlx_data.mlx, mlx_data.width, mlx_data.height);
	mlx_data.img.img_pixels_ptr = mlx_get_data_addr(mlx_data.img.img_ptr, &mlx_data.img.bits_per_pixel, &mlx_data.img.line_length,
								&mlx_data.img.endian);
	mlx_data.precision = 50;
	ft_calculate_mandelbrot_set(&mlx_data);
	mlx_put_image_to_window(mlx_data.mlx,  mlx_data.win, mlx_data.img.img_ptr, 0, 0);

	mlx_mouse_hook(mlx_data.win, &mouse_event, &mlx_data);
	mlx_loop(mlx_data.mlx);

		// Clean Up
	mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
}
