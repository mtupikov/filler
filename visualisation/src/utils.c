/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:14:45 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 13:15:40 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualise.h"

t_2d	vector_at(int x, int y, t_map map)
{
	return (*map.vectors[y * map.width + x]);
}

t_2d	*get_vector(int x, int y, char c)
{
	t_2d *ret;

	if (!(ret = (t_2d *)malloc(sizeof(t_2d))))
		return (NULL);
	ret->y = y;
	ret->x = x;
	ret->c = c;
	return (ret);
}

void	init_p(t_piece *piece)
{
	int		height;

	piece->piece = (char **)malloc(sizeof(char *) * (piece->height));
	height = -1;
	while (++height < piece->height)
		piece->piece[height] = NULL;
}

void	init_vectors(t_map *map)
{
	int		height;
	int		width;

	map->vectors =
			(t_2d **)malloc(sizeof(t_2d *) * (map->height + 1) * (map->width));
	height = -1;
	while (++height <= map->height)
	{
		width = 3;
		while (++width < map->width + 4)
			map->vectors[height * map->width + (width - 4)] = NULL;
	}
}

int		check_if_score(t_mlx *mlx, char *line)
{
	if (ft_strstr(line, "(X)"))
		return (++mlx->red_score);
	else if (ft_strstr(line, "(O)"))
		return (++mlx->green_score);
	return (0);
}
