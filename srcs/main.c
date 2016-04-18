/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:34:01 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/29 15:17:47 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void				init_params(t_params *params)
{
	params->zoom = 6;
	params->alt = 2;
	params->offset.x = 0;
	params->offset.y = 0;
}

int					main(int argc, char **argv)
{
	t_params		e;

	arg_error(argc);
	read_map(&e, argv[1]);
	init_params(&e);
	params.e.mlx = mlx_init();
	params.e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT,
		ft_strcat("FdF @42 ", argv[1]));
	params.img.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	params.img.data = mlx_get_data_addr(e.img.img, &e.img.bpp,
		&e.img.size_line, &e.img.endian);
	mlx_put_image_to_window(e.mlx, e.win, e.img.img,
		e.offset.x, e.offset.y);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
//	mlx_hook(e.win, KeyPress, KeyPressMask, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
