
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/includes/libft.h"
# include <math.h>
# include <X11/keysym.h>
#include <time.h>
# include <stdio.h>

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

// Struct to store the random gradient coefficients
typedef struct s_gradient
{
    double r_mult;
    double g_mult;
    double b_mult;
} t_gradient;

//Todo----------------- Init those structs from scratch -----------------------
typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	double	min_re;
	double	max_re;
	double	min_img;
	double	max_img;
	double	re_factor;
	double	img_factor;
	double	zoom;
	int		zoom_target_x;
	int		zoom_target_y;
	t_bool	zoom_active;
	t_img	img;
	int		precision;
	double	color;
	double	fixed_c_re;
	double	fixed_c_img;
}				t_fractol;

// typedef	struct s_mondelbrot
// {
	
// }				t_mondelbrot;
//Todo -----------------------------------------------------------------------

typedef struct s_complex
{
	double	re;
	double	img;
}				t_complex;

// Struct Utils
void		ft_init_fractol(t_fractol *fractol);
void		ft_init_image_buffer(t_fractol *fractol);
void		ft_clean_fractol(t_fractol *fractol);

// Events Hook
int			ft_mouse_hook(int button, int x, int y, void *param);
int			ft_key_hook(int keycode, void *param);
int			ft_mouse_move_hook(int x, int y, void *param);

// 2D logical plane Utils
void		ft_init_complex_plan(t_fractol *fractol);
t_complex	ft_map_to_complex(t_fractol *fractol, int x, int y);
void		ft_zoom_plan(t_fractol *fractol, double zoom_factor, int mouse_x, int mouse_y);
void		ft_move_plan(t_fractol *fractol, double offset_x, double offset_y);


// Draw functions
void		ft_draw_fractal(t_fractol *fractol);
void		ft_draw_square(t_fractol *fractol);

// Sets
void		ft_mandelbrot_sq_set(t_fractol *fractol, t_complex c, int x, int y);
void		ft_mandelbrot_cub_set(t_fractol *fractol, t_complex c, int x, int y);
void		ft_julia_sq_set(t_fractol *fractol, t_complex c, int x, int y);
void		ft_julia_cub_set(t_fractol *fractol, t_complex c, int x, int y);
void		ft_burningship_sq_set(t_fractol *fractol, t_complex c, int x, int y);
void		ft_burningship_cub_set(t_fractol *fractol, t_complex c, int x, int y);

// Fractol Utils
int			ft_abs(int nbr);
void		ft_my_optimized_pixel_put(t_fractol *fractol, t_img *img, int x, int y, int color);
int			ft_create_psychedelic_color(t_fractol *fractol, int iter);

// Others
void		ft_render_fractal(t_fractol *fractol);
int			ft_loop_hook(t_fractol *fractol);

#endif
