/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:40:23 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 12:43:41 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	put_result(t_point point)
{
	ft_printf("%d %d\n", point.i, point.j);
}

int		check_if_figure_is_ok(t_map *map, t_point point)
{
	int i;
	int j;
	int pi;
	int pj;
	int count;

	count = 0;
	i = point.i - 1;
	pi = map->start.i - 1;
	while (++pi <= map->finish.i && ++i > -1)
	{
		j = point.j - 1;
		pj = map->start.j - 1;
		while (++pj <= map->finish.j && ++j > -1)
		{
			if (check_util_1(map, add_point(i, j), add_point(pi, pj)))
				count++;
			if (map->height < point.i + (map->finish.i - map->start.i) + 1 ||
				map->width < point.j + (map->finish.j - map->start.j) + 1 ||
				i >= map->height || j >= map->width || count > 1 ||
				check_util_2(map, add_point(i, j), add_point(pi, pj)))
				return (0);
		}
	}
	return (count == 1);
}

void	score_util(t_map *map, int score, t_point point)
{
	map->score = score;
	map->final.i = point.i - map->start.i;
	map->final.j = point.j - map->start.j;
}

void	get_score(t_map *map, t_point point)
{
	int i;
	int j;
	int pi;
	int pj;
	int score;

	score = 0;
	i = point.i;
	pi = map->start.i - 1;
	map->can_put++;
	while (++pi <= map->finish.i)
	{
		j = point.j;
		pj = map->start.j - 1;
		while (++pj <= map->finish.j)
		{
			if (map->piece[pi][pj] == '*' && map->heat_map[i][j] != GAMER)
				score += map->heat_map[i][j];
			j++;
		}
		i++;
	}
	if (score < map->score)
		score_util(map, score, point);
}

void	algorithm(t_map *map)
{
	int i;
	int j;

	map->can_put = 0;
	map->score = 99999;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (check_if_figure_is_ok(map, add_point(i, j)))
				get_score(map, add_point(i, j));
		}
	}
	if (map->can_put)
		put_result(map->final);
	else
		exit(1);
}
