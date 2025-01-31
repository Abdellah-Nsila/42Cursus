
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/includes/libft.h"
# include <math.h>
# include <X11/keysym.h>
# include <stdio.h>

typedef struct s_img {
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_line
{
	int beginX;
	int beginY;
	int endX;
	int endY;
	int	color;
}	t_line;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_img	img;
	int     precision;
	int		color1;
	int		color2;
}				t_mlx_data;

void	ft_my_optimized_pixel_put(t_mlx_data *mlx_data, t_img *img, int x, int y, int color);
void	ft_clear_image(t_mlx_data *mlx_data, int color);
void	ft_generate_random_gradient_color(t_mlx_data *mlx_data);
int		ft_get_color(t_mlx_data *mlx_data, int iteration, int max_iterations);


#endif