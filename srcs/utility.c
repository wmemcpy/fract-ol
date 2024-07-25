/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:26:10 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/10 18:03:13 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	atoi_index(char *str, int len)
{
	int		res;
	char	*new;
	int		i;

	new = ft_calloc(sizeof(char), len - 3);
	if (!new)
		return (0);
	i = 4;
	while (i <= len)
	{
		new[i - 4] = str[i];
		++i;
	}
	res = ft_atoi(new);
	free(new);
	return (res);
}

long double	atof_index(char *str, int len)
{
	long double	res;
	char		*new;
	int			i;

	new = ft_calloc(sizeof(char), len - 3);
	if (!new)
		return (0);
	i = 4;
	while (i <= len)
	{
		new[i - 4] = str[i];
		++i;
	}
	res = ft_atof(new);
	free(new);
	return (res);
}

int	type_init(int argc, char **argv)
{
	if (argc >= 2 && !ft_strcmp(argv[1], "mandelbrot"))
		return (0);
	if (argc >= 2 && !ft_strcmp(argv[1], "julia"))
		return (1);
	if (argc >= 2 && !ft_strcmp(argv[1], "burningship"))
		return (2);
	return (-1);
}

void	init_arg(char **argv, t_complex *tmp, int i)
{
	if (argv[i][0] == '-' && argv[i][1] == 'r' && argv[i][2] == 'e' \
		&& argv[i][3] == '=')
		tmp->re = atof_index(argv[i], ft_strlen(argv[i]));
	if (argv[i][0] == '-' && argv[i][1] == 'i' && argv[i][2] == 'm' \
		&& argv[i][3] == '=')
		tmp->im = atof_index(argv[i], ft_strlen(argv[i]));
}
