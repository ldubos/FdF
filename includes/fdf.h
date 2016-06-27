/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:33:47 by ldubos            #+#    #+#             */
/*   Updated: 2016/05/11 17:33:49 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include <stdio.h>

# include "libft.h"
# include "get_next_line.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				endian;

}					t_img;

typedef struct		s_vec3
{
	int				x;
	int				y;
	int				z;
}					t_vec3;

typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_obj
{
	struct s_obj	*p_vertex;
	t_vec3			c_vertex;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_conf
{
	t_env			env;
	t_img			img;
	t_vec2			offset;
	t_obj			*obj;
	t_vec2			pos;
	int				zoom;
	int				alt;
	int				width;
	int				height;
	int				m_width;
}					t_conf;

/*
** error.c
*/

void				arg_error(int ac);
void				open_error(void);
void				gnl_error(int err);
void				malloc_error(void);

/*
** error_2.c
*/

void				square_error(t_conf *conf, int current, char *line);

/*
** obj.c
*/

void				read_obj(t_conf *conf, char *path);
t_vec3				iso(t_conf conf, t_vec3 vertex);
int					get_color(t_vec3 a, t_vec3 b);

/*
** draw.c
*/

void				draw_obj(t_conf conf);

/*
** hook.c
*/

int					key_hook(int keycode, t_conf *conf);
int					loop_hook(t_conf *conf);

#endif
