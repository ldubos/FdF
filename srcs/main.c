/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:34:01 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/26 10:07:26 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				init_conf(t_conf *conf)
{
	conf->env.mlx = mlx_init();
	conf->env.win = mlx_new_window(conf->env.mlx, WIDTH, HEIGHT, "FdF");
	conf->img.img = mlx_new_image(conf->env.mlx, WIDTH, HEIGHT);
	conf->img.data = mlx_get_data_addr(conf->img.img, &conf->img.bpp,
		&conf->img.sl, &conf->img.endian);
	conf->offset = (t_vec2){.x = WIDTH / 2, .y = HEIGHT / 2};
	conf->alt = 3;
	conf->zoom = 15;
	conf->wave = 0;
	conf->wave_s = 0;
	conf->wave_m = 0;
}

int					main(int ac, char **av)
{
	t_conf			conf;

	arg_error(ac);
	init_conf(&conf);
	read_obj(&conf, av[1]);
	draw_obj(conf);
	mlx_put_image_to_window(conf.env.mlx, conf.env.win, conf.img.img, 0, 0);
	mlx_hook(conf.env.win, 2, 1, key_hook, &conf);
	mlx_loop(conf.env.mlx);
	return (0);
}
