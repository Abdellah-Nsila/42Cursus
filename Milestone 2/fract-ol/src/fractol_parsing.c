/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:19:13 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/05 15:20:23 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_bool	ft_check_set_arg(char *set, char *set_arg, char *power, char *power_arg)
{ 
	return (ft_strlcmp(set, set_arg) && ft_strlcmp(power, power_arg));
}

void	ft_exit_on_error(void)
{
	ft_printf("Error: Invalid arguments!\n\
Usage: ./fractol <set> <type>\n\
	[1] ./fractol Mandelbrot\n\
	[3] ./fractol Mandelbrot <sq, cube>\n\
	[2] ./fractol Julia <fixed_x> <fixed_y>\n\
	[4] ./fractol Julia <sq, cube> <fixed_x> <fixed_y>\n");
	exit(EXIT_FAILURE);
}

void	ft_check_parse(t_fractol *fractol, int ac, char **av)
{
	if (ac > 1 && ac < 4)
	{
		if (ac == 2 && ft_strlcmp("Julia", av[1])) // Julia
			ft_exit_on_error();
		else if ((ac == 2 && ft_strlcmp("Mandelbrot", av[1]))
			|| ft_check_set_arg("Mandelbrot", av[1], "sq", av[2])) // Mandelbrot Square
			fractol->set_type = Mandelbrot_sqrt;
		else if (ft_check_set_arg("Julia", av[1], "sq", av[2])) // Julia Square
			fractol->set_type = Julia_sqrt;
		else if (ft_check_set_arg("Mandelbrot", av[1], "cube", av[2])) // Mandelbrot Cube
			fractol->set_type = Mandelbrot_cube;
		else if (ft_check_set_arg("Julia", av[1], "cube", av[2])) // Julia Cube
			fractol->set_type = Julia_cube;
		else
			ft_exit_on_error();
	}
	else
		ft_exit_on_error();
	printf("Set: %d", fractol->set_type);
}


