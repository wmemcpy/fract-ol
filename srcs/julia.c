#include "../includes/main.h"

void	julia(t_vars *vars, int x, int y)
{
	t_complex		z;
	long double		tmp;
	int				i;

	z.re = (x - WIN_WIDTH / 2)
		/ (0.5 * vars->zoom * WIN_WIDTH) + vars->move.re;
	z.im = (y - WIN_HEIGHT / 2)
		/ (0.5 * vars->zoom * WIN_HEIGHT) + vars->move.im;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < vars->max_iter)
	{
		tmp = z.re * z.re - z.im * z.im + vars->c.re;
		z.im = 2 * z.re * z.im + vars->c.im;
		z.re = tmp;
		++i;
	}
	chose_color(vars, x, y, i);
}
