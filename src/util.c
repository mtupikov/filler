/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:50:27 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 12:51:18 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		check_util_1(t_map *map, t_point ij, t_point pp)
{
	return (ft_tolower(map->map[ij.i][ij.j]) == map->gamer &&
			map->piece[pp.i][pp.j] == '*');
}

int		check_util_2(t_map *map, t_point ij, t_point pp)
{
	return (map->piece[pp.i][pp.j] == '*' &&
			ft_tolower(map->map[ij.i][ij.j]) == map->enemy);
}

void	init_hm(t_map *map, int i, int j)
{
	if (j + 1 < map->width && map->heat_map[i][j + 1] == ENEMY)
		map->heat_map[i][j] = 1;
	if (i + 1 < map->height && map->heat_map[i + 1][j] == ENEMY)
		map->heat_map[i][j] = 1;
	if (j + 1 < map->width && i + 1 < map->height &&
		map->heat_map[i + 1][j + 1] == ENEMY)
		map->heat_map[i][j] = 1;
	if (j + 1 < map->width && i - 1 >= 0 &&
		map->heat_map[i - 1][j + 1] == ENEMY)
		map->heat_map[i][j] = 1;
	if (j - 1 >= 0 && map->heat_map[i][j - 1] == ENEMY)
		map->heat_map[i][j] = 1;
	if (i - 1 >= 0 && map->heat_map[i - 1][j] == ENEMY)
		map->heat_map[i][j] = 1;
	if (j - 1 >= 0 && i - 1 >= 0 && map->heat_map[i - 1][j - 1] == ENEMY)
		map->heat_map[i][j] = 1;
	if (j - 1 >= 0 && i + 1 < map->height &&
		map->heat_map[i + 1][j - 1] == ENEMY)
		map->heat_map[i][j] = 1;
}
