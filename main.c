/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:53:09 by okherson          #+#    #+#             */
/*   Updated: 2019/03/15 15:26:45 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			close_window(void *param)
{
	(void)param;
    exit(0);
    return (0);
}

int			main(int argc, char **argv)
{
	t_row	*list;
	t_mas_map	**m_map;
	t_together	*lst;

	if (argc < 2)
		return(write(1, "You hadn't send any argument.", 30));
	else if (argc > 2)
		return(write(1, "YOU send too much arguments", 28));
	list = ft_read_map(&argv[1]);
	if (chack_map(list) == 1)
		return(write(1, "YOU send Invalide map\n", 23));
	m_map = give_mem(list);
	lst = give_tot_mem(m_map);

	mlx_hook(lst->win_ptr, 17, 0, close_window, 0);
	mlx_hook(lst->win_ptr, 2, 0, key_press, lst);
    mlx_loop(lst->mlx_ptr);
	// system("leaks a.out");
	return (0);
}
