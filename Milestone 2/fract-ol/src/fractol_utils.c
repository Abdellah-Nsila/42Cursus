/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:37:37 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/09 13:05:52 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_abs(int nbr)
{
	return ((nbr) * ((nbr >= 0) * 2 - 1));
}

int	ft_get_psychedelic_color(t_fractol *fractol, int iter)
{
	t_rgb	rgb;

	rgb.percent = (double)iter / fractol->precision;
	rgb.percent = log(rgb.percent + 1);
	rgb.scaled_percent = rgb.percent * (PALETTE_SIZE - 1);
	rgb.index1 = (int)rgb.scaled_percent;
	rgb.index2 = (rgb.index1 + 1) % PALETTE_SIZE;
	rgb.fractional = rgb.scaled_percent - rgb.index1;
	rgb.color1 = fractol->palette[rgb.index1];
	rgb.color2 = fractol->palette[rgb.index2];
	rgb.r = (int)(((rgb.color2 >> 16) & 255) * rgb.fractional
			+ ((rgb.color1 >> 16) & 255) * (1 - rgb.fractional));
	rgb.g = (int)(((rgb.color2 >> 8) & 255) * rgb.fractional
			+ ((rgb.color1 >> 8) & 255) * (1 - rgb.fractional));
	rgb.b = (int)((rgb.color2 & 255) * rgb.fractional
			+ (rgb.color1 & 255) * (1 - rgb.fractional));
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

void	ft_generate_random_gradient_color(t_fractol *fractol)
{
	int	i;

	i = 0;
	while (i < PALETTE_SIZE)
	{
		fractol->palette[i] = rand() % 0xFFFFFF;
		i++;
	}
}

void	ft_draw_menu(t_fractol *fractol)
{
	int x = 20;  // Left margin for the text
	int y = 20;  // Top margin for the text
	int color = 0xFFFFFF;  // White color for the text

	mlx_string_put(fractol->mlx, fractol->win, x, y, color,
		"Zoom In: Scroll Up (Mouse Button 4)");
	y += 20;
	mlx_string_put(fractol->mlx, fractol->win, x, y, color,
		"Zoom Out: Scroll Down (Mouse Button 5)");
	y += 20;
	mlx_string_put(fractol->mlx, fractol->win, x, y, color,
		"Increase Iterations: Left Mouse Button (Button 1)");
	y += 20;
	mlx_string_put(fractol->mlx, fractol->win, x, y, color,
		"Decrease Iterations: Right Mouse Button (Button 3)");
	y += 20;
	mlx_string_put(fractol->mlx, fractol->win, x, y, color,
		"Move: Arrow Keys");
	y += 20;
	mlx_string_put(fractol->mlx, fractol->win, x, y, color,
		"Change Colors: Shift Key");
	y += 20;
	mlx_string_put(fractol->mlx, fractol->win, x, y, color,
		"Toggle Mouse Interaction (Julia only): Space Key");
	y += 20;
	mlx_string_put(fractol->mlx, fractol->win, x, y, color,
		"Exit: Escape Key");
}
