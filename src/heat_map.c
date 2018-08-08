/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:45:16 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 12:46:54 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void		init_heat_map(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			if (map->heat_map[i][j] == 0)
				init_hm(map, i, j);
	}
}

static void	fill_map(int i, t_map *map)
{
	int j;

	j = -1;
	while (++j < map->width)
	{
		if (map->map[i][j] == '.')
			map->heat_map[i][j] = 0;
		else if (ft_tolower(map->map[i][j]) == map->gamer)
			map->heat_map[i][j] = GAMER;
		else if (ft_tolower(map->map[i][j]) == map->enemy)
			map->heat_map[i][j] = ENEMY;
	}
}

int			create_heat_map(t_map *map)
{
	int i;

	if (!(map->heat_map = (int **)malloc(sizeof(int *) * map->height)))
		return (0);
	i = -1;
	while (++i < map->height)
	{
		map->heat_map[i] = (int *)malloc(sizeof(int) * map->width);
		fill_map(i, map);
	}
	return (0);
}

static void	calc_hm(t_map *map, int i, int j, int k)
{
	if (j + 1 < map->width && map->heat_map[i][j + 1] == k)
		map->heat_map[i][j] = k + 1;
	if (i + 1 < map->height && map->heat_map[i + 1][j] == k)
		map->heat_map[i][j] = k + 1;
	if (j + 1 < map->width && i + 1 < map->height &&
		map->heat_map[i + 1][j + 1] == k)
		map->heat_map[i][j] = k + 1;
	if (j + 1 < map->width && i - 1 >= 0 && map->heat_map[i - 1][j + 1] == k)
		map->heat_map[i][j] = k + 1;
	if (j - 1 >= 0 && map->heat_map[i][j - 1] == k)
		map->heat_map[i][j] = k + 1;
	if (i - 1 >= 0 && map->heat_map[i - 1][j] == k)
		map->heat_map[i][j] = k + 1;
	if (j - 1 >= 0 && i - 1 >= 0 && map->heat_map[i - 1][j - 1] == k)
		map->heat_map[i][j] = k + 1;
	if (j - 1 >= 0 && i + 1 < map->height && map->heat_map[i + 1][j - 1] == k)
		map->heat_map[i][j] = k + 1;
}

void		calcul_heat_map(t_map *map)
{
	int i;
	int j;
	int k;

	k = 0;
	while (++k < map->width)
	{
		i = -1;
		while (++i < map->height)
		{
			j = -1;
			while (++j < map->width)
				if (map->heat_map[i][j] == 0)
					calc_hm(map, i, j, k);
		}
	}
}
