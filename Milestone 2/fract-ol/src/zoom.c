/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:47:06 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/01 17:52:35 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_draw_square(t_fractol *fractol, int x, int y, int lg, int color)
{
	int i;
	int j;

	i = 0;
	x -= (lg / 2);
	y -= (lg / 2);
	ft_init_image_buffer(fractol);
	while (i < lg)
	{
		j = 0;
		while (j < lg)
		{
			ft_my_optimized_pixel_put(fractol, &fractol->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0, 0);
}

int ft_mouse(int button, int x, int y, void *param)
{
	t_fractol *fractol = param;
	printf("button: %d    x: %d   y: %d\n", button, x, y);

	if (button == 4) // Zoom In
	{
		fractol->zoom /= 1.05; // Increase the zoom factor
	}
	if (button == 5) // Zoom Out
	{
		fractol->zoom *= 1.05; // Decrease the zoom factor
	}

	// Redraw the square with the updated zoom and offset
	ft_draw_square(fractol,(fractol->width / 2), (fractol->height / 2), 300, 0xFF0000);
	return (EXIT_SUCCESS);
}

int	ft_key(int keycode, t_fractol *fractol)
{
	printf("key: %d\n", keycode);
	if (keycode == XK_Escape)
	{
		if (fractol->img.img_ptr)
			mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
		ft_clean_mlx(fractol);
	}
	return (EXIT_SUCCESS);
}

// int main()
// {
// 	t_fractol	fractol;

// 	// Initiale mlx connection with (X/Server) && create window
// 	fractol.mlx = mlx_init();
// 	if (NULL == fractol.mlx)
// 		return (EXIT_FAILURE);
// 	fractol.width = 1000;
// 	fractol.height = 800;
// 	fractol.win = mlx_new_window(fractol.mlx, fractol.width, fractol.height, "Minilbx");
// 	if (NULL == fractol.mlx)
// 	{
// 		free(fractol.mlx);
// 		return (EXIT_FAILURE);
// 	}
// 	fractol.img.img_ptr = NULL;
// 	fractol.zoom = 1.0;
// 	fractol.offset_x = 0;
// 	fractol.offset_y = 0;
// 	ft_draw_square(&fractol, fractol.width / 2, fractol.height / 2, 300, 0xFF0000);

// 	// Lisening for mouse events
// 	mlx_mouse_hook(fractol.win, ft_mouse, &fractol);
// 	mlx_key_hook(fractol.win, ft_key, &fractol);
// 	mlx_loop(fractol.mlx);

// 	// Clean Up
// 	if (fractol.img.img_ptr)
// 		mlx_destroy_image(fractol.mlx, fractol.img.img_ptr);
// 	ft_clean_mlx(&fractol);
// }
