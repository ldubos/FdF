/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:56:59 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/29 15:15:47 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void				put_pixel(t_img *img, t_vec p, int color)
{
	char			*pixel;

	if ((p.x < WIDTH && p.y < HEIGHT) && (p.x >= 0 && p.y >= 0))
	{
		pixel = img->data + p.y * img->size_line + (img->bpp / 8) * p.x;
		pixel[2] = (char)(color >> 16);
		pixel[1] = (char)(color >> 8);
		pixel[0] = (char)(color);
	}
}

void				draw_line_pta(t_img *img, t_vec a, t_vec b,
		int color)
{
	t_vec			p;

	p.x = a.x;
	while (p.x < b.x)
	{
		p.y = a.y + ((b.y - a.y) * (p.x - a.x)) / (b.x - a.x);
		put_pixel(img, p, color);
		++p.x;
	}
}

void				draw_line_ptb(t_img *img, t_vec a, t_vec b,
		int color)
{
	t_vec			p;

	p.y = a.y;
	while (p.y < b.y)
	{
		p.x = a.x + ((b.x - a.x) * (p.y - a.y)) / (b.y - a.y);
		put_pixel(img, p, color);
		++p.y;
	}

}

void				draw_line(t_params *params, t_vec a, t_vec b, int color)
{
	t_vec			p;

	a.x = a.x * params->zoom;
	a.y = a.y * params->zoom;
	b.x = b.x * params->zoom;
	b.y = b.y * params->zoom;

	p.x = a.x - b.x;
	p.y = a.y - b.y;
	if (p.x < 0)
		p.x = -p.x;
	if (p.y < 0)
		p.y = -p.y;
	if (p.x > p.y)
		if (a.x <= b.x)
			draw_line_pta(&params->img, a, b, color);
		else
			draw_line_pta(&params->img, b, a, color);
	else
		if (a.y < b.y)
			draw_line_ptb(&params->img, a, b, color);
		else
			draw_line_ptb(&params->img, b, a, color);
}

void				draw_map(t_params *params)
{
	t_vertices		*ver;

	ver = params->obj->ver;
	while (ver != NULL)
	{
		draw_line(params, get_2d_map(params->obj->ver->point),
			get_2d_map(params->obj->ver->next->point));
		if (params->obj->ver->point.y > 0)
		{
			draw_line(params, get_2d_map(params->obj->ver->point),
				get_2d_map(params->obj->ver->p_point));
		}
	}
}
