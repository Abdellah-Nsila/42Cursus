
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
	double	min_re;
	double	max_re;
	double	min_img;
	double	max_img;
	double	re_factor;
	double	img_factor;
}				t_fractol;
//Todo -----------------------------------------------------------------------

typedef struct s_complex
{
	double	re;
	double	img;
}				t_complex;

// Struct Utils
void		ft_init_fractol(t_fractol *fractol);
void		ft_clean_fractol(t_fractol *fractol);

// Events Hook
int			ft_mouse_hook(int button, int x, int y, void *param);
int			ft_key_hook(int keycode, void *param);

// 2D logical plane Utils
void		ft_init_complex_plan(t_fractol *fractol);
t_complex	ft_map_to_complex(t_fractol *fractol, int x, int y);
void		ft_zoom_plan(t_fractol *fractol, double zoom_factor, int mouse_x, int mouse_y);

// Draw functions
void		ft_draw_square(t_fractol *fractol);

#endif
