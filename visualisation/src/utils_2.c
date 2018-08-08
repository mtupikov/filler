/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:23:01 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 13:24:42 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualise.h"

void	render_util(t_mlx *mlx, t_2d v1, int x, int y)
{
	if (v1.c == mlx->map.green)
		mlx_draw_cell(mlx, 0x2ba320, v1, vector_at(x + 1, y + 1, mlx->map));
	else if (v1.c == mlx->map.red)
		mlx_draw_cell(mlx, 0xa8142c, v1, vector_at(x + 1, y + 1, mlx->map));
	else if (v1.c == ft_toupper(mlx->map.green))
		mlx_draw_cell(mlx, 0x1aff05, v1, vector_at(x + 1, y + 1, mlx->map));
	else if (v1.c == ft_toupper(mlx->map.red))
		mlx_draw_cell(mlx, 0xff0029, v1, vector_at(x + 1, y + 1, mlx->map));
}

void	check_add_vector(t_map *map, int height, int width, const char *line)
{
	char c;

	if (height == map->height)
		c = '.';
	else
		c = line[width];
	map->vectors[height * map->width + width - 4] =
	get_vector(width - 4, height, c);
}

void	map_util(t_map *map, int height, int width, char *line)
{
	check_add_vector(map, height - 1, width, line);
	if (height == map->height)
		check_add_vector(map, height, width, line);
}
