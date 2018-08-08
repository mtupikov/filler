/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:55:34 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/02 13:29:30 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualise.h"

static void		error(char *perke)
{
	ft_printf(perke);
	exit(2);
}

char			*get_name(char *line)
{
	char	*ret;
	int		i;

	i = -1;
	ret = ft_memalloc(sizeof(char) * 20);
	while (*line)
		if (*line++ == '/')
			break ;
	while (*line != '.')
		ret[++i] = *line++;
	ret[++i] = '\0';
	return (ret);
}

void			get_player(t_mlx *mlx, int fd)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < 9)
	{
		get_next_line(fd, &line);
		ft_printf("%s\n", line);
		if (ft_strstr(line, "p1"))
		{
			if (ft_strstr(line, "mtupikov"))
				mlx->green = "mtupikov";
			else
				mlx->green = get_name(line);
		}
		else if (ft_strstr(line, "p2"))
		{
			if (ft_strstr(line, "mtupikov"))
				mlx->red = "mtupikov";
			else
				mlx->red = get_name(line);
		}
		ft_strdel(&line);
	}
}

int				main(int argc, char **argv)
{
	t_mlx *mlx;

	if (!(mlx = init_mlx("filler")))
		error("<==== error when initializng mlx ====>");
	mlx->green_score = 0;
	mlx->red_score = 0;
	mlx->fin = 0;
	mlx->piece.piece = NULL;
	mlx->map.vectors = NULL;
	mlx->map.green = 'o';
	mlx->map.red = 'x';
	get_player(mlx, STDIN_FILENO);
	if (argc < 2 || ft_strcmp(argv[1], "playable") || argc > 3)
		mlx->is_playable = 0;
	mlx_hook(mlx->win, 2, 5, hook_keydown, mlx);
	mlx_loop_hook(mlx->mlx, loop_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
