/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:49:12 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 13:29:01 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static void	read_map(t_map *map)
{
	get_width_and_height(map, 0);
	init_map(map, STDIN_FILENO);
	get_width_and_height(map, 1);
	init_piece(map, STDIN_FILENO);
	check_piece(map);
}

void		get_where(t_map *map)
{
	int		i;
	int		j;
	t_point	g;
	t_point	e;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			if (ft_tolower(map->map[i][j]) == map->gamer)
				g = add_point(i, j);
			else if (ft_tolower(map->map[i][j]) == map->enemy)
				e = add_point(i, j);
	}
	if (g.i > e.i)
		map->where = UP;
	else
		map->where = DOWN;
}

int			main(void)
{
	t_map	map;

	get_player(&map, STDIN_FILENO);
	while (1)
	{
		read_map(&map);
		create_heat_map(&map);
		init_heat_map(&map);
		calcul_heat_map(&map);
		get_where(&map);
		algorithm(&map);
		free_all(&map);
	}
	return (0);
}
