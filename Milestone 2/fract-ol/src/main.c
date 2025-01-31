#include "../includes/fractol.h"

// To compile :
// gcc main.c libmlx_Linux.a  -L/usr/lib -Imlx_linux -lXext -lX11 -lm
// PI = 3.141593

typedef struct s_line_data
{
	int	x;
	int	y;
	int	x_offset;
	int	y_offset;
	int	lg;
	int	color;
}				t_line_data;

void	my_optimized_pixel_put(t_mlx_data *mlx_data, t_img *img, int x, int y, int color)
{
	int	offset;
	if (x >= 0 && x < mlx_data->width && y >= 0 && y < mlx_data->height)
	{
		offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
		*(unsigned int *)(img->img_pixels_ptr + offset) = color;
	}
}

void	ft_draw_line(t_mlx_data *mlx_data, t_line_data line)
{
	int	i;

	i = 0;
	while (i < line.lg)
	{
		mlx_pixel_put(mlx_data->mlx, mlx_data->win, line.x, line.y, line.color);
		line.x += line.x_offset;
		line.y += line.y_offset;
		i++;
	}
}

void	ft_draw_square(t_mlx_data *mlx_data, int x, int y, int lg, int color)
{

	int i;
	int j;

	i = 0;
	x -= (lg / 2);
	y -= (lg / 2);
	while (i < lg)
	{
		j = 0;
		while (j < lg)
		{
			mlx_pixel_put( mlx_data->mlx,  mlx_data->win, x + i, y + j, rand() % 0x1000000);
			j++;
		}
		i++;
	}
}

void	ft_draw_square_border(t_mlx_data *mlx_data, int x, int y, int lg, int color)
{
	int i;
	int j;
	int xw;
	int yh;

	i = 0;
	xw = x - (lg / 2);
	yh = y - (lg / 2);
	while (i < lg)
	{
		j = 0;
		while (j < lg)
		{
			if (i == 0 || j == 0 || i == (lg - 1) || j == (lg - 1))
			{
				// mlx_pixel_put(mlx_data->mlx,  mlx_data->win, xw + i, yh + j, color);
				my_optimized_pixel_put(mlx_data, &mlx_data->img, xw + i, yh + j, color);
			}
			j++;
		}
		i++;
	}
	if (lg > 1)
	{
		ft_draw_square_border(mlx_data, x + (lg / 2), y, lg / 2, 0xff0000);
		ft_draw_square_border(mlx_data, x - (lg / 2), y, lg / 2, 0xff0000);
		ft_draw_square_border(mlx_data, x , y + (lg / 2), lg / 2, 0xff0000);
		ft_draw_square_border(mlx_data, x , y - (lg / 2), lg / 2, 0xff0000);
	}
}

void	ft_color_window(t_mlx_data *mlx_data, int color)
{

	int y;
	int x;

	y = 0;
	while (y < mlx_data->height)
	{
		x = 0;
		while (x < mlx_data->width)
		{
			my_optimized_pixel_put(mlx_data, &mlx_data->img, x, y, color);
			x++;
		}
		y++;
	}
}

int	ft_handle_input(int keysym, t_mlx_data *mlx_data)
{
	printf("The %d key has beem pressed\n", keysym);
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_change_bg(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == XK_r)
		ft_color_window(mlx_data, 0xff0000);
	else if (keysym == XK_g)
		ft_color_window(mlx_data, 0x00ff00);
	else if (keysym == XK_b)
		ft_color_window(mlx_data, 0x0000ff);
	else
		ft_color_window(mlx_data, rand() * 1000000);
	mlx_put_image_to_window(mlx_data->mlx,  mlx_data->win, mlx_data->img.img_ptr, 0, 0);
}

int	main(void)
{
	t_mlx_data	mlx_data;
	void	*mlx;
	void	*win;

	// Init connection &&& window 
	mlx_data.mlx = mlx_init();
	if (NULL == mlx_data.mlx)
		return (EXIT_FAILURE);
	mlx_data.width = 2000;
	mlx_data.height = 1500;
    mlx_data.win = mlx_new_window(mlx_data.mlx, mlx_data.width, mlx_data.height, "Minilbx");
	if (NULL == mlx_data.mlx)
	{
		free(mlx_data.mlx);
		return (EXIT_FAILURE);
	}

	// ft_draw_square(&mlx_data, 450, 350, 450, 0xff0000);
	// mlx_string_put(mlx_data.mlx, mlx_data.win, 650, 600, 0xffffff, "Minilbx");

	// Init Img 
	mlx_data.img.img_ptr = mlx_new_image(mlx_data.mlx, mlx_data.width, mlx_data.height);
	mlx_data.img.img_pixels_ptr = mlx_get_data_addr(mlx_data.img.img_ptr, &mlx_data.img.bits_per_pixel, &mlx_data.img.line_length,
								&mlx_data.img.endian);
	
	// Draw some cheaps
	ft_draw_square_border(&mlx_data, mlx_data.width / 2, mlx_data.height / 2, 500, 0xff0000);
	mlx_put_image_to_window(mlx_data.mlx,  mlx_data.win, mlx_data.img.img_ptr, 0, 0);

	// Event Hook
	// mlx_key_hook(mlx_data.win, ft_change_bg, &mlx_data);

	// Window Loop
    mlx_loop(mlx_data.mlx);

	// Clean Up
	mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
}
