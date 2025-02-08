/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_plan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:13:26 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/08 19:19:04 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void ft_init_complex_plan(t_fractol *fractol)
{
    double center_re = -0.5; // Center of the Mandelbrot set
    double center_img = 0.0;
    double range_re = 3.5;   // Initial real axis range (covers -2.0 to 1.5)

    // Calculate imaginary range to match window aspect ratio
    double range_img = range_re * fractol->height / fractol->width;

    // Set complex plane boundaries
    fractol->min_re = center_re - (range_re / 2.0);
    fractol->max_re = center_re + (range_re / 2.0);
    fractol->min_img = center_img - (range_img / 2.0);
    fractol->max_img = center_img + (range_img / 2.0);

    // Compute mapping factors
    fractol->re_factor = (fractol->max_re - fractol->min_re) / fractol->width;
    fractol->img_factor = (fractol->max_img - fractol->min_img) / fractol->height;
}

t_complex	ft_map_to_complex(t_fractol *fractol, int x, int y)
{
	t_complex	c;

	c.re = fractol->min_re + (x * fractol->re_factor);
	c.img = fractol->max_img - (y * fractol->img_factor);
	return (c);
}

#define MIN_RANGE_RE 0.00000000000000370074
#define MIN_RANGE_IMG 0.00000000000000289122


// TODO You can chose to keep the range plan dimension and the ft_map_to_complex      (but the over zoom destry the window)
// TODO or just center the window, and convertthe cord and zoom by direct calculation (but the bad flexibility on change dimension)
void	ft_zoom_plan(t_fractol *fractol, double zoom_factor, int mouse_x, int mouse_y)
{
    double old_range_re = fractol->max_re - fractol->min_re;
    double old_range_img = fractol->max_img - fractol->min_img;
    double new_range_re = old_range_re / zoom_factor;
    double new_range_img = old_range_img / zoom_factor;
    double new_re_factor, new_img_factor;
    double mouse_re, mouse_img;
	printf("range re: %.20f\n", new_range_re);
	printf("range img: %.20f\n", new_range_img);

    // Clamp the new range so it doesn't get too small
    if (new_range_re < MIN_RANGE_RE)
        new_range_re = MIN_RANGE_RE;
    if (new_range_img < MIN_RANGE_IMG)
        new_range_img = MIN_RANGE_IMG;

    new_re_factor = new_range_re / fractol->width;
    new_img_factor = new_range_img / fractol->height;
    
    // Map the mouse position to its current complex coordinate
    mouse_re = fractol->min_re + mouse_x * (old_range_re / fractol->width);
    mouse_img = fractol->max_img - mouse_y * (old_range_img / fractol->height);
    
    // Compute new boundaries so that the complex coordinate at (mouse_x, mouse_y) remains fixed.
    fractol->min_re = mouse_re - mouse_x * new_re_factor;
    fractol->max_re = fractol->min_re + new_range_re;
    
    fractol->max_img = mouse_img + mouse_y * new_img_factor;
    fractol->min_img = fractol->max_img - new_range_img;
    
    // Update mapping factors
    fractol->re_factor = new_re_factor;
    fractol->img_factor = new_img_factor;
    
    // Update the zoom level
    fractol->zoom *= zoom_factor;
}



// void	ft_zoom_plan(t_fractol *fractol, double zoom_factor, int mouse_x, int mouse_y)
// {
//     double old_range_re = fractol->max_re - fractol->min_re;
//     double old_range_img = fractol->max_img - fractol->min_img;
//     double new_range_re = old_range_re / zoom_factor;
//     double new_range_img = old_range_img / zoom_factor;
//     double new_re_factor = new_range_re / fractol->width;
//     double new_img_factor = new_range_img / fractol->height;
    
//     // Map the mouse pixel to its complex coordinate
//     double mouse_re = fractol->min_re + mouse_x * (old_range_re / fractol->width);
//     double mouse_img = fractol->max_img - mouse_y * (old_range_img / fractol->height);
    
//     // Compute new boundaries so that the complex coordinate at (mouse_x, mouse_y) remains unchanged.
//     fractol->min_re = mouse_re - mouse_x * new_re_factor;
//     fractol->max_re = fractol->min_re + new_range_re;
    
//     // For the imaginary axis, note the y=0 at the top.
//     fractol->max_img = mouse_img + mouse_y * new_img_factor;
//     fractol->min_img = fractol->max_img - new_range_img;
    
//     // Update mapping factors to new values
//     fractol->re_factor = new_re_factor;
//     fractol->img_factor = new_img_factor;
    
//     // Update the zoom level (optional if you want to keep track)
//     // fractol->zoom *= zoom_factor;
// }


// void	ft_init_complex_plan(t_fractol *fractol)
// {
// 	fractol->center.x = fractol->width / 2;
// 	fractol->center.y = fractol->height / 2;
// 	fractol->re_factor = (fractol->width / 4) * fractol->zoom;
// 	fractol->img_factor = (fractol->height / 4) * fractol->zoom;

// }

// void	ft_zoom_plan(t_fractol *fractol, double zoom_factor, int mouse_x, int mouse_y)
// {
// 	fractol->center.x = mouse_x + (fractol->center.x - mouse_x) * zoom_factor;
// 	fractol->center.y = mouse_y + (fractol->center.y - mouse_y) * zoom_factor;
// 	fractol->zoom *= zoom_factor;

// 	fractol->re_factor = (fractol->width / 4) * fractol->zoom;
// 	fractol->img_factor = (fractol->height / 4) * fractol->zoom;
// }

void	ft_move_plan(t_fractol *fractol, double offset_x, double offset_y)
{
	fractol->min_re += offset_x;
	fractol->max_re += offset_x;
	fractol->min_img += offset_y;
	fractol->max_img += offset_y;

	fractol->re_factor = (fractol->max_re - fractol->min_re) / (fractol->width - 1);
	fractol->img_factor = (fractol->max_img - fractol->min_img) / (fractol->height - 1);
}
