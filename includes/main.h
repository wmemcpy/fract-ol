#ifndef MAIN_H
# define MAIN_H

// write, close, read
# include <unistd.h>
// open,
# include <fcntl.h>
// malloc, free, exit
# include <stdlib.h>
// perror 
# include <stdio.h> 
// strerror
# include <string.h>

# include <stdbool.h>

# include <stdint.h>
# include <math.h>

// include libs
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

// define
# define WIN_WIDTH		542
# define WIN_HEIGHT		542

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}	t_color;

typedef struct s_complex
{
	long double		re;
	long double		im;
}	t_complex;

typedef struct s_screen
{
	int				x;
	int				y;
}	t_screen;

typedef struct s_vars
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				type;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	long double		zoom;
	int				max_iter;
	t_screen		window_pos;
	t_complex		c;
	t_complex		move;
}	t_vars;

// prototypes
// main.c
bool		print_param(void);
bool		init(t_vars *vars, t_complex tmp, int fractal_type, int iter);
void		start(t_vars *vars);
bool		set_input(int argc, char **argv, t_vars *vars);

// draw.c
void		chose_color(t_vars *vars, int x, int y, int i);
void		fractal(t_vars *vars);

// input.c
int			key_hook(int keycode, t_vars *vars);
int			mouse_hook(int button, int x, int y, t_vars *vars);
int			close_window(t_vars *vars);

// utility.c
int			atoi_index(char *str, int len);
long double	atof_index(char *str, int len);
int			type_init(int argc, char **argv);
long double	ft_atof_index(const char *str);
void		init_arg(char **argv, t_complex *tmp, int i);

// generation
void		mandelbrot(t_vars *vars, int x, int y);
void		julia(t_vars *vars, int x, int y);
void		burningship(t_vars *vars, int x, int y);

#endif