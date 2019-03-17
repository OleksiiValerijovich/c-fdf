/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:57:32 by okherson          #+#    #+#             */
/*   Updated: 2019/03/15 14:58:58 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	angle(int key, t_together *lst)
{
	x = buff->map_chars->x;
        y = buff->map_chars->y;
        z = buff->map_chars->z;
        j == 6 ? buff->map_chars->x = x * cos(i) + z * sin(i) : 0;
        j == 6 ? buff->map_chars->z = -x * sin(i) + z * cos(i) : 0;
        j == 12 ? buff->map_chars->x = ((x * cos(i) - y * sin(i))) : 0;
        j == 12 ? buff->map_chars->y = ((y * cos(i) + x * sin(i))) : 0;
        j == 0 ? buff->map_chars->y = (y * cos(i) + z * sin(i)) : 0;
        j == 0 ? buff->map_chars->z = (-y * sin(i) + z * cos(i)) : 0;
        buff = buff->next;
}