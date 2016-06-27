/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:03:32 by ldubos            #+#    #+#             */
/*   Updated: 2016/05/11 14:01:21 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_obj				*save_vertices(t_conf *conf, t_obj **prev, char *line,
	t_obj **obj)
{
	t_obj			*r_prev;
	t_obj			*t_prev;
	char			**split;

	(!(r_prev = (t_obj *)malloc(sizeof(t_obj)))) ? malloc_error() : NULL;
	t_prev = r_prev;
	split = ft_strsplit(line, ' ');
	while (split[conf->pos.x])
	{
		if (!(*prev))
			((*(obj)))->p_vertex = NULL;
		else
			((*(obj)))->p_vertex = ((*(prev)));
		((*(obj)))->c_vertex.x = conf->pos.x;
		((*(obj)))->c_vertex.y = conf->pos.y;
		((*(obj)))->c_vertex.z = ft_atoi(split[conf->pos.x++]);
		t_prev->c_vertex = ((*(obj)))->c_vertex;
		if (!(((*(obj)))->next = (t_obj *)malloc(sizeof(t_obj))))
			malloc_error();
		(!(t_prev->next = (t_obj *)malloc(sizeof(t_obj)))) ? malloc_error() : 0;
		((*(obj))) = ((*(obj)))->next;
		t_prev = t_prev->next;
		(!(!((*(prev))))) ? ((*(prev))) = ((*(prev)))->next : NULL;
	}
	return (r_prev);
}

void				read_obj(t_conf *conf, char *path)
{
	int				fd;
	int				err;
	t_obj			*prev;
	t_obj			*tmp;
	char			*line;

	conf->pos.y = 0;
	prev = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		open_error();
	if (!(conf->obj = (t_obj *)malloc(sizeof(t_obj))))
		malloc_error();
	tmp = conf->obj;
	while ((err = get_next_line(fd, &line)) > 0)
	{
		conf->pos.x = 0;
		prev = save_vertices(conf, &prev, line, &tmp);
		square_error(conf, conf->pos.x, line);
		++conf->pos.y;
	}
	tmp->next = NULL;
	gnl_error(err);
	close(fd);
}

t_vec3				iso(t_conf conf, t_vec3 vertex)
{
	t_vec3			ret;

	ret.x = vertex.x * conf.zoom - vertex.y * conf.zoom;
	ret.y = vertex.y * conf.zoom - cos(30 * M_PI / 180) *
	(vertex.z * conf.alt) + sin(30 * M_PI / 180) * (vertex.z * conf.alt);
	ret.x += conf.offset.x;
	ret.y += conf.offset.y;
	return (ret);
}

int					get_color(t_vec3 a, t_vec3 b)
{
	if (a.z <= -1 || b.z <= -1)
	{
		if (a.z <= -6 || b.z <= -3)
		{
			if (a.z <= -12 || b.z <= -12)
				return (0x002C4C);
			return (0x20647F);
		}
		return (0x468499);
	}
	if (a.z >= 1 || b.z >= 1)
	{
		if (a.z >= 10 || b.z >= 10)
		{
			if (a.z >= 12 || b.z >= 12)
				return (0xFFFFFF);
			return (0x696969);
		}
		return (0x53802D);
	}
	return (0x6F502C);
}
