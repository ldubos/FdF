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
	e->t_x = 0;
	str_split = ft_strsplit(line, ' ');
	while (str_split[e->t_x] != 0)
	{
		save->ver->p_point = pp->point;
		save->ver->point.x = tmp->point.x = e->t_x;
		save->ver->point.y = tmp->point.y = e->t_y;
		save->ver->point.x = tmp->point.z = ft_atoi(str_split[e->t_x]);
		if ((save->ver->next =
			ret->next = (t_vertices *)malloc(sizeof(t_vertices))) == NULL)
			malloc_error();
		pp = pp->next;
		save = save->next;
		++e->t_x;
	}
	return(ret);
}

void				read_obj(t_params *e, char *path)
{
	int				fd;
	char			*line;
	t_vec			*p_points;
	t_vec			*save;

	if ((fd = open(path, O_RDONLY)) == -1)
		open_error();
	if ((e->obj->ver = (t_vertices *)malloc(sizeof(t_vertices))) == NULL)
		malloc_error();
	save = e->obj->ver;
	p_points = NULL;
	while (gnl_error(get_next_line(fd, &line)) > 0)
	{
		p_points = save_vec(e, line, p_points, &save);
		++e->t_y;
	}
	save->next = NULL;
	free(e->save);
	free(p_points);
	close(fd);
}

t_vec				3d_obj_to_iso(t_vec vertex)
{
	t_vec			ret;

	ret.x = vertex.x - vertex.y;
	ret.y = vertex.z + vertex.x + vertex.y;
	return (ret);
}
