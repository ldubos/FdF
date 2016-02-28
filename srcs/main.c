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
	params->alt = 3;
	params->offset.x = 0;
	params->offset.y = 0;
	params->redraw = 1;
}

int					main(int argc, char **argv)
{
	t_params		params;

	arg_error(argc);
	read_map(&params, argv[1]);
	init_params(&params);
	params.e.mlx = mlx_init();
	params.e.win = mlx_new_window(params.e.mlx, WIDTH, HEIGHT, "FdF @42");
	params.img.img = mlx_new_image(params.e.mlx, params.map.max.x * 8,
		params.map.max.x * 8);
	params.img.data = mlx_get_data_addr(params.img.img, &params.img.bpp,
						&params.img.size_line, &params.img.endian);
	mlx_put_image_to_window(params.e.mlx, params.e.win, params.img.img,
		params.offset.x, params.offset.y);
	mlx_key_hook(params.e.win, key_hook, &params);
	mlx_loop_hook(params.e.mlx, loop_hook, &params);
//	mlx_hook(params.e.win, KeyPress, KeyPressMask, key_hook, &params);
	mlx_loop(params.e.mlx);
	return (0);
}
