/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:47:11 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 12:49:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_point			add_point(int i, int j)
{
	t_point	point;

	point.i = i;
	point.j = j;
	return (point);
}

void			check_piece(t_map *map)
{
	char	**arr;
	int		i;
	int		j;
	t_point points[map->piece_height * map->piece_width];

	arr = map->piece;
	i = -1;
	while (++i < map->piece_height)
	{
		j = -1;
		while (++j < map->piece_width)
			if (arr[i][j] != '.')
				points[j + i * map->piece_width] = add_point(i, j);
			else
				points[j + i * map->piece_width] = add_point(-1, -1);
	}
	map->start = add_point(get_min_h(map, points, 1),
			get_min_w(map, points, 1));
	map->finish = add_point(get_max_h(map, points, 1),
			get_max_w(map, points, 1));
}

void			init_piece(t_map *map, int fd)
{
	char	**piece;
	int		height;

	height = 0;
	piece = (char **)malloc(sizeof(char *) * (map->piece_height));
	while (height < map->piece_height)
	{
		get_next_line(fd, &piece[height]);
		height++;
	}
	map->piece = piece;
}

void			init_map(t_map *map, int fd)
{
	char	**big_map;
	char	*line;
	int		height;

	height = 0;
	big_map = (char **)malloc(sizeof(char *) * (map->height + 1));
	while (height <= map->height)
	{
		get_next_line(fd, &line);
		if (height != 0)
		{
			big_map[height - 1] = (char *)malloc(sizeof(char) * map->width);
			ft_strcpy(big_map[height - 1], line + 4);
		}
		ft_strdel(&line);
		height++;
	}
	map->map = big_map;
}

void			get_width_and_height(t_map *map, int piece)
{
	char *line;
	char *t;

	get_next_line(STDIN_FILENO, &line);
	t = line;
	while (*line)
	{
		if (ft_isdigit(*line))
			break ;
		line++;
	}
	if (piece)
		map->piece_height = ft_atoi(line);
	else
		map->height = ft_atoi(line);
	while (ft_isdigit(*line) && *line)
		line++;
	if (piece)
		map->piece_width = ft_atoi(line);
	else
		map->width = ft_atoi(line);
	ft_strdel(&t);
}
