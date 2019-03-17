/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_iso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:32:18 by okherson          #+#    #+#             */
/*   Updated: 2019/03/17 09:25:30 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    send(int x1, int x2, int y1, int y2, t_together *lst)
{

    int     x[2];
    int     y[2];

    x[0] = lst->m[y1][x1].chx /** lst->zoom + lst->pos[0]*/;
    x[1] = lst->m[y1][x2].chx /** lst->zoom + lst->pos[0]*/;
    y[0] = lst->m[y1][x1].chy /** lst->zoom + lst->pos[1]*/;
    y[1] = lst->m[y2][x1].chy /** lst->zoom + lst->pos[1]*/;
    // printf("%d,%d,%d,%d ", lst->m[y1][x1].chy, lst->m[y1][x1].chx, lst->m[y2][x1].chy, lst->m[y1][x2].chx);
    // printf("%d,%d,%d,%d ", x[0], y[0], x[1], y[1]);
    line_put(lst->mlx_ptr, lst->win_ptr, x, y, lst->m[y1][x1].chcolor);
}

void    paint_iso(t_together *lst)
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
                send(x, x + 1, y, y, lst);
            if ((y + 1) < lst->tyx[0])
                send(x, x, y, y + 1, lst);
            x++;
        }
        y++;
        // printf("\n\n");
    }
}