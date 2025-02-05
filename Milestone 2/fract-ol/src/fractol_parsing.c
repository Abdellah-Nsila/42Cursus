/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:19:13 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/05 17:37:21 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//TODO Use you ft-strtod to get x, y for Julia set and compet parsing and strture files and check norm
//TODO You can check for an other random method for coloring, optimize, leaks check , smothly also, clean code , utils file, go to others repo / internet and get some ideas 

t_bool	ft_check_set_arg(char *set, char *set_arg, char *power, char *power_arg)
{ 
	return (ft_strlcmp(set, set_arg) && ft_strlcmp(power, power_arg));
}

void	ft_exit_on_error(void)
{
	ft_printf("Error: Invalid arguments!\n\
Usage: ./fractol <set> <type>\n\
	[1] ./fractol Mandelbrot\n\
	[3] ./fractol Mandelbrot <square, cube>\n\
	[2] ./fractol Julia <fixed_x> <fixed_y>\n\
	[4] ./fractol Julia <square, cube> <fixed_x> <fixed_y>\n\
	[2] ./fractol Burningship\n\
	[4] ./fractol Burningship <square, cube>\n");
	exit(EXIT_FAILURE);
}

void	ft_check_parse(t_fractol *fractol, int ac, char **av)
{
	if (ac > 1 && ac < 4)
	{
		if (ac == 2 && ft_strlcmp("Julia", av[1]))
			ft_exit_on_error();
		else if ((ac == 2 && ft_strlcmp("Mandelbrot", av[1]))
			|| ft_check_set_arg("Mandelbrot", av[1], "square", av[2]))
			fractol->set_type = Mandelbrot_square;
		else if (ft_check_set_arg("Mandelbrot", av[1], "cube", av[2]))
			fractol->set_type = Mandelbrot_cube;
		else if (ft_check_set_arg("Julia", av[1], "square", av[2]))
			fractol->set_type = Julia_square;
		else if (ft_check_set_arg("Julia", av[1], "cube", av[2]))
			fractol->set_type = Julia_cube;
		else if ((ac == 2 && ft_strlcmp("Burningship", av[1]))
			|| ft_check_set_arg("Burningship", av[1], "square", av[2]))
			fractol->set_type = Burningship_square;
		else if (ft_check_set_arg("Burningship", av[1], "cube", av[2]))
			fractol->set_type = Burningship_cube;
		else
			ft_exit_on_error();
	}
	else
		ft_exit_on_error();
}


