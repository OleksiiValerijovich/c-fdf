/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:59:27 by okherson          #+#    #+#             */
/*   Updated: 2019/03/15 11:49:42 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		convert_color(char *str)
{
	int a;
	int b;
	int c;
	int num;
	int	l;
	char	**color_write;

	color_write = ft_strsplit(str, 'x');
	a = 5;
	b = 0;
	num = 0;
	l = ft_strlen(color_write[1]);
	if (l != 6)
		write(1, "What is that color?!\n", 16);
	while (a >= 0)
	{
		if (color_write[1][b] >= '0' && color_write[1][b] <= '9')
			c = color_write[1][b] - '0';
		else if (color_write[1][b] >= 'A' && color_write[1][b] <= 'F')
			c = color_write[1][b] - 55;
		num = num + c * pow(16, a);
		a--;
		b++;
	}
	return(num);
}

void	put_z(t_row *list, t_mas_map **map)
{
	int		x;
	int		y;
	char	**h_vs_color;

	y = 0;
	
	while (y < map[0][0].map_size[0])
	{
		x = 0;
		while(x < map[0][0].map_size[1])
		{
			h_vs_color = ft_strsplit(list->row_el[x], ',');
			map[y][x].fz = ft_atoi(h_vs_color[0]);
			if (h_vs_color[1] != NULL)
				map[y][x].fcolor = convert_color(h_vs_color[1]);
			else
				map[y][x].fcolor = 255255255;
			free(h_vs_color);
			x++;
		}
		y++;
		list = list->next;
	}
}

t_mas_map	**give_mem(t_row *list)
{
	t_mas_map	**map;
	t_row 		*l = NULL;
	int			a;
	int			b;

	l = list;
	while (list->next != NULL)
		list = list->next;
	a = 0;
	map = ft_memalloc(list->row_num * sizeof(t_mas_map *));
	// map[9] = NULL;
	while (a < list->row_num)
	{
		b = 0;
		map[a] = ft_memalloc(list->el_num * sizeof(t_mas_map));
		ft_bzero((void *)(map[a]), sizeof(t_mas_map));
		a++;
	}
	map[0][0].map_size[0] = list->row_num;
	map[0][0].map_size[1] = list->el_num;
	put_z(l, map);
    return(map);
}
