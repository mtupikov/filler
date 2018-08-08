/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:44:02 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 12:44:11 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static void	free_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->height)
		free(map->map[i]);
	free(map->map);
}

static void	free_piece(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->piece_height)
		free(map->piece[i]);
	free(map->piece);
}

static void	free_hm(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->height)
		free(map->heat_map[i]);
	free(map->heat_map);
}

void		free_all(t_map *map)
{
	free_piece(map);
	free_map(map);
	free_hm(map);
}
