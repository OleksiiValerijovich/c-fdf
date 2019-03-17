/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_1p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:32:18 by okherson          #+#    #+#             */
/*   Updated: 2019/03/15 14:00:50 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    send_param(int x1, int x2, int y1, int y2, t_together *lst)
{

    int     x[2];
    int     y[2];

    x[0] = ((lst->m[y1][x1].fx) * 20 + 690);
    x[1] = (lst->m[y1][x2].fx * 20 + 690);
    y[0] = (lst->m[y1][x1].fy * 20 + 410);
    y[1] = (lst->m[y2][x1].fy * 20 + 410);
    line_put(lst->mlx_ptr, lst->win_ptr, x, y, lst->m[y1][x1].fcolor);
}

void    paint_1p(t_together *lst)
{
    int y;
    int x;

    y = 0;
    while (y < lst->tyx[0])
    {
        x = 0;
        while (x < lst->tyx[1])
        {
            if ((x + 1) < lst->tyx[1])
                send_param(x, x + 1, y, y, lst);
            if ((y + 1) < lst->tyx[0])
                send_param(x, x, y, y + 1, lst);
            x++;
        }
        y++;
    }
}