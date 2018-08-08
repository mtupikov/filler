/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:16:01 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 13:16:09 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualise.h"

static int		line_g(t_mlx *mlx, t_2d *p1, t_2d *p2, int color)
{
	if (p1->x < 0 || p1->x >= X_SCREEN_SIZE ||
		p1->y < 0 || p1->y >= Y_SCREEN_SIZE ||
		p2->x < 0 || p2->x >= X_SCREEN_SIZE ||
		p2->y < 0 || p2->y >= Y_SCREEN_SIZE ||
		(p1->x == p2->x && p1->y == p2->y))
		return (1);
	img_set_pixel(mlx->image, p1->x, p1->y, color);
	mlx->l.err2 = mlx->l.err;
	if (mlx->l.err2 > -mlx->l.dx)
	{
		mlx->l.err -= mlx->l.dy;
		p1->x += mlx->l.sx;
	}
	if (mlx->l.err2 < mlx->l.dy)
	{
		mlx->l.err += mlx->l.dx;
		p1->y += mlx->l.sy;
	}
	return (0);
}

void			vector_change(t_2d *p, t_mlx *mlx)
{
	p->x *= 1500 / (mlx->map.width + mlx->map.height);
	p->y *= 1500 / (mlx->map.width + mlx->map.height);
	p->x += 50;
	p->y += 50;
}

static void		mlx_put_line(t_2d p1, t_2d p2, t_mlx *mlx, int color)
{
	t_line line;

	vector_change(&p1, mlx);
	vector_change(&p2, mlx);
	line.start = p1;
	line.stop = p2;
	line.dx = ABS(p2.x - p1.x);
	line.sx = p1.x < p2.x ? 1 : -1;
	line.dy = ABS(p2.y - p1.y);
	line.sy = p1.y < p2.y ? 1 : -1;
	line.err = ((line.dx > line.dy) ? line.dx : -line.dy) / 2;
	mlx->l = line;
	while (1)
		if (line_g(mlx, &p1, &p2, color))
			break ;
}

void			mlx_draw_cell(t_mlx *mlx, int color, t_2d p1, t_2d p2)
{
	int		i;
	int		j;

	vector_change(&p1, mlx);
	vector_change(&p2, mlx);
	i = p1.x;
	while (++i < p2.x)
	{
		j = p1.y;
		while (++j < p2.y)
			img_set_pixel(mlx->image, i, j, color);
	}
}

void			render_image(t_mlx *mlx)
{
	t_2d	v1;
	int		x;
	int		y;

	x = -1;
	while (++x < mlx->map.width)
	{
		y = -1;
		while (++y <= mlx->map.height)
		{
			v1 = vector_at(x, y, mlx->map);
			if (x + 1 < mlx->map.width)
				mlx_put_line(v1, vector_at(x + 1, y, mlx->map), mlx, 0xFFFFFF);
			if (y + 1 <= mlx->map.height)
				mlx_put_line(v1, vector_at(x, y + 1, mlx->map), mlx, 0xFFFFFF);
			if (x + 1 < mlx->map.width && y + 1 <= mlx->map.height)
				render_util(mlx, v1, x, y);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->img, 0, 0);
}
