/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:27:53 by okherson          #+#    #+#             */
/*   Updated: 2019/03/14 11:02:11 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_mas(t_mas_map **m_map)
{
	int		x;
	int		y;

	y = 0;
	while (y < m_map[0][0].map_size[0])
	{
		x = 0;
		while (x < m_map[0][0].map_size[1])
		{
			printf("%d	", m_map[y][x].fz);
			x++;
		}
		printf("\n");
		y++;
	}
}