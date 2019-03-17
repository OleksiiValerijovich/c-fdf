/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:53:54 by okherson          #+#    #+#             */
/*   Updated: 2019/03/15 15:28:01 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(int key, t_together *lst)
{
	if (key == 123)
		lst->pos[0] = lst->pos[0] - 20;
	iso(lst);
}

int    key_press(int key, t_together *lst)
{
	if (key == 53)
		exit(0);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move(key, lst);
	// else if (key == 27 || key == 24)
	// 	zoom(key, lst);
	// else if (key == 0 || key == 1 || key == 2 || key == 13)
	// 	angle(key, lst);
	else if (key == 18)
	{
		mlx_clear_window(lst->mlx_ptr, lst->win_ptr);
		paint_1p(lst);
	}
	else if (key == 19)
	{
		mlx_clear_window(lst->mlx_ptr, lst->win_ptr);
		lst->hz = 1;
		iso(lst);
	}
	// else if (key == 20)
	// 	;
	// else if (key == 8 || key == 9)
	// 	color(key, lst);
	return (0);
}