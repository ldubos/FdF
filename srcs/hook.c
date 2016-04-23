/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:37:17 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/23 09:33:09 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define SPEED 30

int					key_hook(int keycode, t_params *params)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 123)
		params->offset.x -= SPEED;
	if (keycode == 124)
		params->offset.x += SPEED;
	if (keycode == 126)
		params->offset.y -= SPEED;
	if (keycode == 125)
		params->offset.y += SPEED;
	if (keycode == 69 || keycode == 78)
	{
		if (keycode == 69 && params->zoom <= 20)
			params->zoom += 1;
		if (keycode == 78 && params->zoom >= 1)
			params->zoom -= 1;
		draw_obj(params);
	}
	mlx_clear_window(params->mlx, params->win);
	mlx_put_image_to_window(params->mlx, params->win, params->img.img, 0, 0);
	return (0);
}

int					loop_hook(t_params *params)
{
/*	if (params->redraw == 1)
	{
		mlx_clear_window(params->mlx, params->win);
		ft_bzero(params->img.data, WIDTH * 4 * HEIGHT * 4 * 4);
		draw_obj(params);
		mlx_put_image_to_window(params->mlx, params->win, params->img.img,
			params->offset.x, params->offset.y);
		params->redraw = 0;
	}*/
	return (0);
}
