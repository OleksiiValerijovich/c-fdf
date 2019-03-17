/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_tot_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:00:50 by okherson          #+#    #+#             */
/*   Updated: 2019/03/17 09:36:33 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_xy(t_together  *lst)
{
	int		x;
	int		y;

	y = 0;
	while (y < lst->tyx[0])
	{
		x = 0;
		while(x < lst->tyx[1])
		{
   			lst->m[y][x].fx = x;
			lst->m[y][x].chx = x;
			lst->m[y][x].fy = y;
			lst->m[y][x].chy = y;
			lst->m[y][x].chcolor = lst->m[y][x].fcolor;
			x++;
		}
		y++;
	}
}

t_together      *give_tot_mem(t_mas_map **m_map)
{
    t_together  *lst;

    lst = malloc(sizeof(t_together));
    lst->tyx[0] = m_map[0][0].map_size[0];
    lst->tyx[1] = m_map[0][0].map_size[1];
    lst->m = m_map;
    lst->zoom = 20;
	lst->win_size[0] = 1200;
	lst->win_size[1] = 1600;
	lst->pos[0] = (lst->win_size[0] - lst->tyx[0] * lst->zoom) / 2;
	lst->pos[1] = (lst->win_size[1] - lst->tyx[1] * lst->zoom) / 2;
	lst->angle = 0.523599;
	lst->hz = 1;
    lst->mlx_ptr = mlx_init();
    lst->win_ptr = mlx_new_window(lst->mlx_ptr, 1600, 1200, "fdf");
    put_xy(lst);
    paint_1p(lst);
    return (lst);
}