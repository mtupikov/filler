/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:00:51 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 13:10:34 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualise.h"

int			get_width_and_height(t_mlx *mlx, char *line, int piece)
{
	char *t;

	if (!line)
		return (0);
	t = line;
	ft_printf("%s\n", line);
	while (*line)
	{
		if (ft_isdigit(*line))
			break ;
		line++;
	}
	if (!piece)
		mlx->map.height = ft_atoi(line);
	else
		mlx->piece.height = ft_atoi(line);
	while (ft_isdigit(*line) && *line)
		line++;
	if (!piece)
		mlx->map.width = ft_atoi(line);
	else
		mlx->piece.width = ft_atoi(line);
	ft_strdel(&t);
	return (1);
}

int			init_piece(t_piece *piece, int fd)
{
	int		height;
	char	*line;

	height = 0;
	if (!piece->piece)
		init_p(piece);
	while (height < piece->height)
	{
		get_next_line(fd, &line);
		piece->piece[height] = line;
		ft_strdel(&line);
		ft_printf("%s\n", piece->piece[height]);
		height++;
	}
	return (1);
}

int			init_map(t_map *map, int fd)
{
	char	*line;
	int		height;
	int		width;

	height = -1;
	if (!map->vectors)
		init_vectors(map);
	while (++height <= map->height)
	{
		get_next_line(fd, &line);
		if (line)
		{
			ft_printf("%s\n", line);
			if (height > 0)
			{
				width = 3;
				while (++width < map->width + 4)
					map_util(map, height, width, line);
			}
			ft_strdel(&line);
		}
	}
	return (1);
}

static void	rm_util(t_mlx *mlx, char *line, int fd)
{
	if (check_if_score(mlx, line))
	{
		ft_strdel(&line);
		get_next_line(fd, &line);
	}
	if (ft_strstr(line, "Plateau"))
	{
		get_width_and_height(mlx, line, 0);
		init_map(&mlx->map, fd);
	}
	else if (ft_strstr(line, "Piece"))
	{
		get_width_and_height(mlx, line, 1);
		init_piece(&mlx->piece, fd);
	}
	else if (ft_strstr(line, "fin"))
	{
		mlx->fin = 1;
		ft_strdel(&line);
	}
	else
	{
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
}

int			read_map(int fd, t_mlx *mlx)
{
	char *line;

	get_next_line(fd, &line);
	if (line)
		rm_util(mlx, line, fd);
	return (1);
}
