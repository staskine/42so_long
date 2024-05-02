/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:50:45 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 13:56:42 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_status(t_node *game)
{
	if (game->exit_x == game->p_x && game->exit_y == game->p_y
		&& game->coins == 0)
	{
		ft_putendl_fd("YOU WON THE GAME", 1);
		mlx_close_window(game->mlx42);
	}
}

void	delete_collectible(t_node *game, int height, int len)
{
	int	i;

	i = 0;
	len = len * game->tile_size;
	height = height * game->tile_size;
	while (i < game->og_coins)
	{
		if (game->image.col->instances[i].x == len
			&& game->image.col->instances[i].y == height)
		{
			if (game->image.col->instances[i].enabled != false)
			{
				game->image.col->instances[i].enabled = false;
				game->coins--;
			}
		}
		i++;
	}
}
