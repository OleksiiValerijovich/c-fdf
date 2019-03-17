/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:57:42 by okherson          #+#    #+#             */
/*   Updated: 2019/03/17 08:52:35 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft_GNL/libft.h"

#include <stdio.h>

typedef struct	s_mas_map
{
	int			map_size[2];
	int			fx;
	int			fy;
	int			fz;
	int			fcolor;
	int			chy;
	int			chx;
	int			chz;
	int			chcolor;
}    			t_mas_map;

typedef struct	s_together
{
	t_mas_map		**m;
	int         	tyx[2];
	int				zoom;
	int				win_size[2];
	int				pos[2];
	double			angle;
	int				hz;
	void    		*win_ptr;
	void    		*mlx_ptr;
}               t_together;

typedef struct		s_row
{
	char			*row;
	int				row_num;
	char			**row_el;
	int				el_num;
	struct s_row	*next;
}					t_row;

t_row		*ft_read_map(char **argv);
int			chack_map(t_row *list);
t_mas_map	**give_mem(t_row *list);
t_together  *give_tot_mem(t_mas_map **m_map);
void		paint_1p(t_together *lst);
int			key_press(int key, t_together *lst);
void		iso(t_together *lst);
void    	paint_iso(t_together *lst);
void		line_put(void *mlx_ptr, void *win_ptr, int *x, int *y, int color);

 void    	print_mas(t_mas_map **m_map); 

#endif

