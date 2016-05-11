/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:37:17 by ldubos            #+#    #+#             */
/*   Updated: 2016/05/11 14:03:53 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define SPEED 30
#define ZOOM_SPEED 1
#define ALT_SPEED 1
#define MAX_ALT_WAVE 30
#define WAVE_FREQ 1

void				key_listener(int keycode, t_conf *conf)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 69)
		conf->zoom += ZOOM_SPEED;
	if (keycode == 78)
		conf->zoom -= ZOOM_SPEED;
	if (keycode == 116)
		conf->alt += ALT_SPEED;
	if (keycode == 121)
		conf->alt -= ALT_SPEED;
	if (keycode == 126)
		conf->offset.y -= SPEED;
	if (keycode == 125)
		conf->offset.y += SPEED;
	if (keycode == 123)
		conf->offset.x -= SPEED;
	if (keycode == 124)
		conf->offset.x += SPEED;
	if (conf->wave == 0 && keycode == 49)
		conf->wave = 1;
	else if (conf->wave == 1 && keycode == 49)
		conf->wave = 0;
}

int					key_hook(int keycode, t_conf *conf)
{
	key_listener(keycode, conf);
	mlx_destroy_image(conf->env.mlx, conf->img.img);
	conf->img.img = mlx_new_image(conf->env.mlx, WIDTH, HEIGHT);
	draw_obj(*conf);
	mlx_clear_window(conf->env.mlx, conf->env.win);
	mlx_put_image_to_window(conf->env.mlx, conf->env.win, conf->img.img, 0, 0);
	return (0);
}

int					loop_hook(t_conf *conf)
{
	if (conf->wave == 1)
	{
		if (conf->wave_m > WAVE_FREQ * 2)
			conf->wave_m = 0;
		if (conf->wave_s == 0 && conf->wave_m % WAVE_FREQ)
		{
			conf->alt += ALT_SPEED;
			conf->wave_m += 1;
		}
		if (conf->wave_s == 1 && conf->wave_m % WAVE_FREQ)
		{
			conf->alt += ALT_SPEED;
			conf->wave_m += 1;
		}
		if (conf->wave_s == 0 && conf->alt >= MAX_ALT_WAVE)
			conf->wave_s = 1;
		if (conf->wave_s == 1 && conf->alt <= -MAX_ALT_WAVE)
			conf->wave_s = 0;
	}
	mlx_destroy_image(conf->env.mlx, conf->img.img);
	conf->img.img = mlx_new_image(conf->env.mlx, WIDTH, HEIGHT);
	draw_obj(*conf);
	mlx_clear_window(conf->env.mlx, conf->env.win);
	mlx_put_image_to_window(conf->env.mlx, conf->env.win, conf->img.img, 0, 0);
	return (0);
}
