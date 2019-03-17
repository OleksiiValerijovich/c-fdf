/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:28:25 by okherson          #+#    #+#             */
/*   Updated: 2019/03/05 15:39:10 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_row		*ft_read_map(char **str)
{
	int		fd;
	int		b;
	char	*line;
	t_row	*s;
	t_row	*list;

	s = malloc(sizeof(t_row));
	list = s;
	fd = open(*str, O_RDONLY);
	b = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (b != 0)
		{
			s->next = malloc(sizeof(t_row));
			s = s->next;
		}
		s->row = ft_strdup(line);
		s->row_el = ft_strsplit(line, ' ');
		s->row_num = b + 1;
		s->next = NULL;
		b++;
		free(line);
	}
	return (list);
}
