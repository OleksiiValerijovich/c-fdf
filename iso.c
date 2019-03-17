/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:34:00 by okherson          #+#    #+#             */
/*   Updated: 2019/03/17 10:23:09 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso(t_together *lst)
{
	int		a;
	int		b;
	int		xp;
	int		yp;

	a = 0;
	while (a < lst->tyx[0])
	{
		b = 0;
		while (b < lst->tyx[1])
		{
			xp = lst->m[a][b].chx;
			yp = lst->m[a][b].chy;
			// printf("%d,%d->", yp, xp);
    		lst->m[a][b].chx = ((xp + yp) * lst->zoom) * cos(lst->angle) + lst->pos[1];
		    lst->m[a][b].chy = ((xp - yp) * lst->zoom) * sin(lst->angle) - lst->m[a][b].chz + lst->pos[0];
			printf("%f, %f,	", sin(lst->angle), cos(lst->angle));
			// printf("%d, %d, %d->	", lst->m[a][b].chy, lst->m[a][b].chx, lst->m[a][b].chz);

			b++;
		}
		printf("\n");
		a++;
	}
	mlx_clear_window(lst->mlx_ptr, lst->win_ptr);
	paint_iso(lst);
}
