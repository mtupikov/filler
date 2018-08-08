/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:51:41 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 12:53:25 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

/*
**  <=== DEFINES ===>
*/

# define ENEMY  (-1)
# define GAMER  (-2)
# define UP		1
# define DOWN	0
# define ABS(x) ((x) < 0 ? -(x) : (x))

/*
**  <=== STRUCTS ===>
*/

typedef struct
{
	int			i;
	int			j;
}				t_point;

typedef struct
{
	char		gamer;
	char		enemy;
	char		**map;
	char		**piece;
	int			**heat_map;
	int			height;
	int			width;
	int			score;
	int			piece_height;
	int			piece_width;
	int			where;
	int			can_put;
	t_point		final;
	t_point		start;
	t_point		finish;
}				t_map;

/*
**  <=== PROTOTYPES ===>
*/

/*
**  init.c
*/

void			check_piece(t_map *map);
void			init_piece(t_map *map, int fd);
void			init_map(t_map *map, int fd);
void			get_width_and_height(t_map *map, int piece);
t_point			add_point(int i, int j);

/*
**  get_point.c
*/

int				get_max_w(t_map *map, t_point *points, int mop);
int				get_max_h(t_map *map, t_point *points, int mop);
int				get_min_w(t_map *map, t_point *points, int mop);
int				get_min_h(t_map *map, t_point *points, int mop);
void			get_player(t_map *map, int fd);

/*
**  algorithm.c
*/

void			put_result(t_point point);
void			algorithm(t_map *map);
int				check_if_figure_is_ok(t_map *map, t_point point);

/*
**  heat_map.c
*/

int				create_heat_map(t_map *map);
void			calcul_heat_map(t_map *map);
void			init_heat_map(t_map *map);

/*
**  util.c
*/

int				check_util_1(t_map *map, t_point ij, t_point pp);
int				check_util_2(t_map *map, t_point ij, t_point pp);
void			init_hm(t_map *map, int i, int j);

/*
**  free_all.c
*/

void			free_all(t_map *map);

#endif
