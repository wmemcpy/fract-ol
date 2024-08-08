#include "../includes/main.h"

bool	print_param(void)
{
	ft_putstr_fd("Usage: ./fractol [SECTION] [OPTION...]\nSECTION:\
	\n\tmandelbrot\n\tjulia\n\tburningship\nOPTIONS:\
	\n\t-i=[ITERATION]\t\t: set the number of iteration (∈ ℕ)\n\t\
	-re=[Real] -im=[Im]: set the complex number (Re + Im) (julia only)\n", 2);
	return (false);
}

bool	init(t_vars *vars, t_complex tmp, int fractal_type, int iter)
{
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		return (false);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIN_HEIGHT, WIN_WIDTH, \
		"fractol");
	if (!vars->win_ptr)
		return (false);
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	vars->addr = mlx_get_data_addr(vars->img_ptr, &vars->bits_per_pixel, \
		&vars->line_length, &vars->endian);
	vars->zoom = 0.5;
	vars->max_iter = iter;
	vars->window_pos.x = 0;
	vars->window_pos.y = 0;
	vars->c.re = tmp.re;
	vars->c.im = tmp.im;
	vars->move.re = 0;
	vars->move.im = 0;
	vars->type = fractal_type;
	return (true);
}

void	start(t_vars *vars)
{
	mlx_hook(vars->win_ptr, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win_ptr, 4, 1L << 2, mouse_hook, vars);
	mlx_hook(vars->win_ptr, 17, 1L << 17, close_window, vars);
	fractal(vars);
	mlx_loop(vars->mlx_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
}

bool	set_input(int argc, char **argv, t_vars *vars)
{
	size_t		i;
	int			iter;
	int			type;
	t_complex	tmp;

	type = -1;
	iter = 70;
	tmp.re = -0.7;
	tmp.im = 0.27015;
	i = 1;
	type = type_init(argc, argv);
	if (type != -1 && argc > 2)
	{
		while (argv[i])
		{
			if (argv[i][0] == '-' && argv[i][1] == 'i' && argv[i][2] == '=')
				iter = ft_atoi(argv[i] + 3);
			init_arg(argv, &tmp, i);
			i++;
		}
	}
	if (type == -1 || iter < 0)
		return (print_param());
	return (init(vars, tmp, type, iter));
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (set_input(argc, argv, &vars))
		start(&vars);
	return (0);
}
