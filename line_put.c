/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 10:48:26 by okherson          #+#    #+#             */
/*   Updated: 2019/03/15 14:46:37 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_horiz(void *mlx_ptr,void *win_ptr, int *x, int *y, float a, int c)
{
	int		xp;
	float	yp;

	xp = x[0];
	yp = y[0];
	while (xp <= x[1])
	{
		mlx_pixel_put(mlx_ptr, win_ptr, xp, roundf(yp), c);
		yp += a;
		xp++;
	}
}

void		put_vert(void *mlx_ptr,void *win_ptr, int *x, int *y, float a, int c)
{
	float		xp;
	int	yp;

	xp = x[0];
	yp = y[0];
	while (yp <= y[1])
	{
		mlx_pixel_put(mlx_ptr, win_ptr, roundf(xp), yp, c);
		xp += a;
		yp++;
	}
}

static void	int_repl(int *n, int *m)
{
	int		c;

	c = *n;
	*n = *m;
	*m = c;
}

void	line_put(void *mlx_ptr,void *win_ptr, int *x, int *y, int color)
{
	float	a[2];

	if (x[0] > x[1])
		int_repl(&x[0], &x[1]);
	if (y[0] > y[1])
		int_repl(&y[0], &y[1]);
	if ((y[1] - y[0]) == 0)
		a[0] = 0;
	else
		a[0] = (float)((float)(x[1] - x[0])/(float)(y[1] - y[0]));
	if ((x[1] - x[0]) == 0)
		a[1] = 0;
	else
		a[1] = (float)((y[1] - y[0])/(x[1] - x[0]));
	if (x[1] == x[0] && y[1] == y[0])
		mlx_pixel_put(mlx_ptr, win_ptr, x[0], y[0], color);
	else if (x[1] - x[0] >= y[1] - y[0])
		put_horiz(mlx_ptr, win_ptr, x, y, a[1], color);
	else
		put_vert(mlx_ptr, win_ptr, x, y, a[0], color);
}
