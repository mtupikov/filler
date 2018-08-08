/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:44:26 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 12:45:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	get_player(t_map *map, int fd)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "mtupikov") && ft_strstr(line, "p1"))
	{
		map->gamer = 'o';
		map->enemy = 'x';
	}
	else if (ft_strstr(line, "mtupikov") && ft_strstr(line, "p2"))
	{
		map->gamer = 'x';
		map->enemy = 'o';
	}
	ft_strdel(&line);
}

int		get_max_w(t_map *map, t_point *points, int mop)
{
	int	max;
	int i;
	int height;
	int width;

	if (mop)
	{
		height = map->piece_height;
		width = map->piece_width;
	}
	else
	{
		height = map->height;
		width = map->width;
	}
	i = 0;
	max = -1;
	while (i < width * height)
	{
		if (points[i].j > max && points[i].j != -1)
			max = points[i].j;
		i++;
	}
	return (max);
}

int		get_min_w(t_map *map, t_point *points, int mop)
{
	int	min;
	int i;
	int height;
	int width;

	if (mop)
	{
		height = map->piece_height;
		width = map->piece_width;
	}
	else
	{
		height = map->height;
		width = map->width;
	}
	i = 0;
	min = 100;
	while (i < width * height)
	{
		if (points[i].j < min && points[i].j != -1)
			min = points[i].j;
		i++;
	}
	return (min);
}

int		get_max_h(t_map *map, t_point *points, int mop)
{
	int	max;
	int	i;
	int height;
	int width;

	if (mop)
	{
		height = map->piece_height;
		width = map->piece_width;
	}
	else
	{
		height = map->height;
		width = map->width;
	}
	i = 0;
	max = -1;
	while (i < width * height)
	{
		if (points[i].i > max && points[i].i != -1)
			max = points[i].i;
		i++;
	}
	return (max);
}

int		get_min_h(t_map *map, t_point *points, int mop)
{
	int	min;
	int	i;
	int height;
	int width;

	if (mop)
	{
		height = map->piece_height;
		width = map->piece_width;
	}
	else
	{
		height = map->height;
		width = map->width;
	}
	i = 0;
	min = 100;
	while (i < width * height)
	{
		if (points[i].i < min && points[i].i != -1)
			min = points[i].i;
		i++;
	}
	return (min);
}
