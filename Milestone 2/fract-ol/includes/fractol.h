
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/includes/libft.h"
# include <math.h>
# include <X11/keysym.h>
# include <stdio.h>

//Todo----------------- Init this struct from scratch -----------------------
typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}				t_fractol;
//Todo -----------------------------------------------------------------------



#endif
