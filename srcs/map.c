/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:03:32 by ldubos            #+#    #+#             */
/*   Updated: 2016/02/01 12:11:29 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertices			*save_vec(t_params *p, char *line, t_vertices *pp,
							  t_vertices **save)
{
	char			**str_split;
	t_vertices		*ret;
	t_vertices		*tmp;

	if ((ret = (t_vertices *)malloc(sizeof(t_vertices))) == NULL)
		malloc_error();
	tmp = ret;
	p->t_x = 0;
	str_split = ft_strsplit(line, ' ');
	while (str_split[p.t_x] != 0)
	{
		save->ver->p_point = pp->point;
		save->ver->point.x = tmp->point.x = p->t_x;
		save->ver->point.y = tmp->point.y = p->t_y;
		save->ver->point.x = tmp->point.z = ft_atoi(str_split[p->t_x]);
		if ((save->ver->next =
			ret->next = (t_vertices *)malloc(sizeof(t_vertices))) == NULL)
			malloc_error();
		pp = pp->next;
		save = save->next;
		++p->t_x;
	}
	return(ret);
}

void				read_map(t_params *p, char *path)
{
	int				fd;
	char			*line;
	t_vec			*p_points;

	p_points = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		open_error();
	if ((p->obj->ver = (t_vertices *)malloc(sizeof(t_vertices))) == NULL)
		malloc_error();
	p->save = p->obj->ver;
	while (gnl_error(get_next_line(fd, &line)) > 0)
	{
		p_points = save_vec(p, line, p_points, &save_a);
		++p->t_y;
	}
	save->next = NULL;
	close(fd);
}

t_vec				get_2d_map(t_vec map)
{
	t_vec			ret;

	ret.x = map.x - map.y;
	ret.y = map.z + map.x + map.y;
	return (ret);
}
