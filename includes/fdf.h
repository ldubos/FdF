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

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
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
	t_img			img;
	t_obj			obj;
	t_vec			offset;
	t_vec			rot;
	int				t_x;
	int				t_y;
	int				alt;
	int				zoom;
	int				redraw;
	void			*mlx;
	void			*win;
}					t_params;

/*
** error.c
*/

void				arg_error(int argc);
void				open_error();
int					gnl_error(int err);
void				malloc_error();

/*
** obj.c
*/

void				read_obj(t_params *e, char *path);
t_vec				3d_obj_to_iso(t_vec vertex);

/*
** hook.h
*/

int					key_hook(int keycode, t_params *params);
int					loop_hook(t_params *e);

/*
** draw.c
*/

void				draw_line(t_params *e, t_vec a, t_vec b, int color);
void				draw_obj(t_params *e);

#endif
