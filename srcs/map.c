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

void				fill_map(t_params *params, t_list *lst)
{
	t_vec			index;
	t_vec			tmp;

	index = (t_vec){.x = 0, .y = 0, .z = 0};
	if (!(params->map.map = (t_vec **)malloc(sizeof(t_vec *) *
	params->map.max.y)))
		malloc_error();
	while (index.y < params->map.max.y)
	{
		if (!(params->map.map[index.y] =
			(t_vec *)malloc(sizeof(t_vec) * params->map.max.x)))
			malloc_error();
		++index.y;
	}
	while (lst)
	{
		tmp = *((t_vec *)lst->content);
		params->map.map[tmp.y][tmp.x] = tmp;
		lst = lst->next;
	}
}

void				read_map(t_params *params, char *path)
{
	t_vec			file;
	t_list			*tmp;
	char			*line;
	char			**tmp_x;

	tmp = NULL;
	file.x = open(path, O_RDONLY);
	params->map.max.y = 0;
	while ((file.y = get_next_line(file.x, &line)) > 0)
	{
		gnl_error(file.y);
		tmp_x = ft_strsplit(line, ' ');
		params->map.max.x = 0;
		while (tmp_x[params->map.max.x])
		{
			params->map.max.z = -ft_atoi(tmp_x[params->map.max.x]);
			ft_lstadd(&tmp, ft_lstnew(&params->map.max, sizeof(t_vec)));
			++params->map.max.x;
		}
		++params->map.max.y;
	}
	fill_map(params, tmp);
	close(file.x);
}

t_vec				get_2d_map(t_vec map)
{
	t_vec			ret;

	ret.x = map.x - map.y;
	ret.y = map.z + map.x + map.y;
	return (ret);
}
