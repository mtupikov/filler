/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:59:19 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 13:25:16 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualise.h"

t_mlx	*mlx_destroyer(t_mlx *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->image != NULL)
		del_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx	*init_mlx(char *title)
{
	t_mlx	*ret;

	if (!(ret = (t_mlx *)malloc(sizeof(t_mlx))))
		return (mlx_destroyer(ret));
	if (!(ret->mlx = mlx_init()) ||
		(!(ret->win = mlx_new_window(ret->mlx,
		X_SCREEN_SIZE, Y_SCREEN_SIZE, title))) ||
		(!(ret->image = new_image(ret))))
		return (mlx_destroyer(ret));
	return (ret);
}
