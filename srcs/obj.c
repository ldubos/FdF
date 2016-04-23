/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:03:32 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/23 08:45:45 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void				save_vec(t_params *e, t_raw *raw)
{
	char			**str_split;

	if ((e->obj = (t_vec **)malloc(sizeof(t_vec *) * e->t_y)) == NULL)
		malloc_error();
	str_split = ft_strsplit(raw->data, ' ');
	while (str_split[e->t_x] != 0)
		++e->t_x;
	while (e->t_y-- > 0)
		if ((e->obj[e->t_y] = (t_vec *)malloc(sizeof(t_vec) * e->t_x)) == NULL)
			malloc_error();	
	e->t_y = 0;
	while (raw != NULL)
	{
		printf("raw =>\t\"%s\"\n", raw->data);
		e->t_x = 0;
		str_split = ft_strsplit(raw->data, ' ');
		printf("\t\tOK (AFTER STR_SPLIT INIT)\n");
		while (str_split[e->t_x] != 0)
		{
			e->obj[e->t_y][e->t_x].x = e->t_x;
			e->obj[e->t_y][e->t_x].y = e->t_y;
			e->obj[e->t_y][e->t_x].z = ft_atoi(str_split[e->t_x]);
			++e->t_x;
		}
		printf("\t\tOK (AFTER LOOP STR_SPLIT)\n");
		++e->t_y;
		raw = raw->next;
		(raw->next == NULL) ? printf("\t\tRAW->NEXT (NULL)\n") : printf("\t\tRAW->NEXT (NOT NULL)\n");
		printf("\t\tOK (AFTER RAW->NEXT)\n");
	}
	printf("\t\tOK (AFTER LOOP RAW)\n");
}

void				read_obj(t_params *e, char *path)
{
	int				fd;
	char			*line;
	int				err;
	t_raw			*raw;
	t_raw			*tmp;

	e->t_y = 0;
	e->t_x = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		open_error();
	if ((raw = (t_raw *)malloc(sizeof(t_raw))) == NULL)
		malloc_error();
	tmp = raw;
	while ((err = get_next_line(fd, &line)) > 0)
	{
		gnl_error(err);
		++e->t_y;
		tmp->data = line;
		if ((tmp->next = (t_raw *)malloc(sizeof(t_raw))) == NULL)
			malloc_error();
		tmp = tmp->next;
	}
	tmp->next = NULL;
	(tmp->next == NULL) ? printf("\t\tOK (TMP->NEXT == NULL)\n") : printf("\t\tKO (TMP->NEXT == NULL)\n");
	free(tmp);
	close(fd);
	save_vec(e, raw);
}

t_vec				obj_to_iso(t_vec vertex)
{
	t_vec			ret;

	ret.x = vertex.x - vertex.y;
	ret.y = vertex.z + vertex.x + vertex.y;
	return (ret);
}
