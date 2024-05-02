/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:22:27 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 14:04:11 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_collectibles(t_node *game)
{
	int	i;
	int	j;
	int	t_s;

	i = 0;
	t_s = game->tile_size;
	while (i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			if (game->map[i][j] == 'C')
			{
				if (mlx_image_to_window(game->mlx42, game->image.col,
						(j * t_s), (i * t_s)) < 0)
					exit_mlx(game->map, game, "Image to window failed");
			}
			j++;
		}
		i++;
	}
}

void	add_floor(t_node *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			if (game->map[i][j] != '1')
			{
				if (mlx_image_to_window(game->mlx42, game->image.floor,
						j * game->tile_size, i * game->tile_size) < 0)
					exit_mlx(game->map, game, "Image to window failed");
			}
			j++;
		}
		i++;
	}
}

void	add_walls(t_node *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			if (game->map[i][j] == '1')
			{
				if (mlx_image_to_window(game->mlx42, game->image.wall,
						j * game->tile_size, i * game->tile_size) < 0)
					exit_mlx(game->map, game, "Image to window failed");
			}
			j++;
		}
		i++;
	}
}

void	image_to_window(t_node *game)
{
	int	t_s;

	t_s = game->tile_size;
	add_walls(game);
	add_floor(game);
	add_collectibles(game);
	if (mlx_image_to_window(game->mlx42, game->image.exit,
			game->exit_x * t_s, game->exit_y * t_s) < 0)
		exit_mlx(game->map, game, "Image to window failed");
	if (mlx_image_to_window(game->mlx42, game->image.p,
			game->p_x * t_s, game->p_y * t_s) < 0)
		exit_mlx(game->map, game, "Image to window failed");
}
