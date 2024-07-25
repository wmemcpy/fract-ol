/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:45:39 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/08 02:47:51 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static long double	ft_fabs(long double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	burningship(t_vars *vars, int x, int y)
{
	t_complex		z;
	t_complex		o;
	long double		tmp;
	int				i;

	o.re = 0;
	o.im = 0;
	z.re = (x - WIN_WIDTH / 2)
		/ (0.5 * vars->zoom * WIN_WIDTH) + vars->move.re;
	z.im = (y - WIN_HEIGHT / 2)
		/ (0.5 * vars->zoom * WIN_HEIGHT) + vars->move.im;
	i = 0;
	while (o.re * o.re + o.im * o.im <= 4 && i < vars->max_iter)
	{
		tmp = o.re * o.re - o.im * o.im + z.re;
		o.im = 2 * ft_fabs(o.re * o.im) + z.im;
		o.re = tmp;
		i++;
	}
	chose_color(vars, x, y, i);
}
