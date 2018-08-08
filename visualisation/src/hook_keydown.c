/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keydown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:53:46 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 12:54:15 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualise.h"

static void	more_info(t_mlx *mlx, char *green_sc, char *red_sc, char *tmp)
{
	green_sc = ft_itoa(mlx->green_score);
	red_sc = ft_itoa(mlx->red_score);
	mlx_string_put(mlx->mlx, mlx->win, 1150, 50, 0x000000, mlx->green);
	tmp = ft_strjoin("Score: ", green_sc);
	mlx_string_put(mlx->mlx, mlx->win, 1150, 80, 0x000000, tmp);
	ft_strdel(&tmp);
	mlx_string_put(mlx->mlx, mlx->win, 1150, 300, 0x000000, mlx->red);
	tmp = ft_strjoin("Score: ", red_sc);
	mlx_string_put(mlx->mlx, mlx->win, 1150, 330, 0x000000, tmp);
	ft_strdel(&tmp);
	ft_strdel(&red_sc);
	ft_strdel(&green_sc);
}

static void	put_info(t_mlx *mlx)
{
	char *green_sc;
	char *tmp;
	char *red_sc;

	green_sc = NULL;
	red_sc = NULL;
	tmp = NULL;
	more_info(mlx, green_sc, red_sc, tmp);
	if (mlx->fin)
	{
		if (mlx->green_score > mlx->red_score)
		{
			tmp = ft_strjoin(mlx->green, " has won!");
			mlx_string_put(mlx->mlx, mlx->win, 1400, 800, 0x000000, tmp);
			ft_strdel(&tmp);
		}
		else
		{
			tmp = ft_strjoin(mlx->red, " has won!");
			mlx_string_put(mlx->mlx, mlx->win, 1400, 800, 0x000000, tmp);
			ft_strdel(&tmp);
		}
	}
}

int			loop_hook(t_mlx *mlx)
{
	read_map(STDIN_FILENO, mlx);
	render_image(mlx);
	put_info(mlx);
	return (1);
}

int			hook_keydown(int key)
{
	if (key == KEY_ESC)
		exit(EXIT_SUCC);
	return (0);
}
