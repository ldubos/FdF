#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

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
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_vec
{
	int				x;
	int				y;
	int				z;
}					t_vec;

typedef struct		s_vertices
{
	t_vec			p_point;
	t_vec			point;
	s_vertices		*next;
}

typedef struct		s_obj
{
	t_vec			origin;
	t_vertices		*ver;
}					t_obj;

typedef struct		s_params
{
	t_env			e;
	t_img			img;
	t_obj			obj;
	t_vec			offset;
	t_vertices		*save;
	int				t_x;
	int				t_y;
	int				alt;
	int				zoom;
	int				redraw;
}					t_params;

/*
** error.c
*/

void				arg_error(int argc);
void				open_error();
int					gnl_error(int err);
void				malloc_error();

/*
** map.c
*/

void				read_map(t_params *params, char *path);
t_vec				get_2d_map(t_vec point);

/*
** hook.h
*/

int					key_hook(int keycode, t_params *params);
int					loop_hook(t_params *params);

/*
** draw.c
*/

void				draw_line(t_params *params, t_vec a, t_vec b, int color);
void				draw_map(t_params *params);

#endif
