#include "../includes/fractol.h"

// TODO Good recources video : https://github.com/Gontjarow/MiniLibX/blob/master/docs/index.md



void    ft_draw_line(t_mlx_data *mlx_data, t_line *line)
{
	double deltaX = line->endX - line->beginX;
	double deltaY = line->endY - line->beginY;
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX /= pixels;
	deltaY /= pixels;

	double pixelX = line->beginX;
	double pixelY = line->beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx_data->mlx, mlx_data->win, pixelX, pixelY, line->color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

int main()
{
	t_mlx_data	mlx_data;
	t_line		line;;

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

	line.beginX = 0;
	line.beginY = 0;
	line.endX = mlx_data.width;
	line.endY = mlx_data.height;
	line.color = 0xFFFFFF;
	ft_draw_line(&mlx_data, &line);
	mlx_loop(mlx_data.mlx);
}