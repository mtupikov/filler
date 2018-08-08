/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:30:40 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 13:30:41 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISE_H
# define VISUALISE_H

/*
** <--- INCLUDES --->
*/

# include "../miniLibX/mlx.h"
# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"
# include <stdio.h>
# include <math.h>
# include "keys.h"

/*
** <--- DEFINES --->
*/

# define X_SCREEN_SIZE	1920
# define Y_SCREEN_SIZE	1080
# define EXIT_SUCC		1
# define ABS(x)			((x) < 0 ? -(x) : (x))

/*
** <--- STRUCTS --->
*/

typedef struct	s_2d
{
	int			x;
	int			y;
	char		c;
}				t_2d;

typedef struct	s_map
{
	int			width;
	int			height;
	char		green;
	char		red;
	t_2d		**vectors;
}				t_map;

typedef struct	s_image
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

typedef struct	s_piece
{
	char		**piece;
	int			width;
	int			height;
}				t_piece;

typedef struct	s_line
{
	t_2d		start;
	t_2d		stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			is_playable;
	t_image		*image;
	t_piece		piece;
	t_map		map;
	t_line		l;
	char		*green;
	char		*red;
	int			green_score;
	int			red_score;
	int			fin;
}				t_mlx;

/*
** <--- PROTOTYPES --->
*/

/*
** mlx_stuff.c
*/

t_mlx			*init_mlx(char *title);

/*
** image.c
*/

void			img_set_pixel(t_image *image, int x, int y, int color);
t_image			*del_image(t_mlx *mlx, t_image *img);
t_image			*new_image(t_mlx *mlx);

/*
** read_map.c
*/

int				read_map(int fd, t_mlx *mlx);

/*
** render.c
*/

void			render_image(t_mlx *mlx);
void			mlx_draw_cell(t_mlx *mlx, int color, t_2d p1, t_2d p2);

/*
** hook_keydown.c
*/

int				hook_keydown(int key);
int				loop_hook(t_mlx *mlx);

/*
** utils.c
*/

t_2d			vector_at(int x, int y, t_map map);
t_2d			*get_vector(int x, int y, char c);
void			init_p(t_piece *piece);
void			init_vectors(t_map *map);
int				check_if_score(t_mlx *mlx, char *line);

/*
** utils_2.c
*/

void			check_add_vector(t_map *map, int height, int width,
				const char *line);
void			render_util(t_mlx *mlx, t_2d v1, int x, int y);
void			free_all(t_mlx *mlx);
void			map_util(t_map *map, int height, int width, char *line);

#endif
