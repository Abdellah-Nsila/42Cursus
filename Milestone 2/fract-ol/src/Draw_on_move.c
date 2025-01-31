#include "../includes/fractol.h"

int mouse_event(int button, int x, int y, void *param)
{
	t_mlx_data *mlx_data;

	mlx_data = param;
	printf("Mouse Button: %d\n", button);
	mlx_pixel_put(mlx_data->mlx, mlx_data->win, x, y, rand() * 1000000);
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

	mlx_mouse_hook(mlx_data.win, &mouse_event, &mlx_data);
	mlx_loop(mlx_data.mlx);
}