/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:02:39 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 13:58:11 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_node *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_none(1);
	game->map = get_map(fd);
	parse_map(game);
}

void	so_long(char *file)
{
	static t_node	game;

	check_valid(file);
	initialize_map(&game, file);
	get_tile_size(&game);
	game.mlx42 = mlx_init(game.tile_size * game.x,
			game.tile_size * game.y, "Game", false);
	if (!game.mlx42)
		exit_mlx(game.map, &game, "Initializing mlx fail");
	initialize_images(&game);
	image_to_window(&game);
	mlx_key_hook(game.mlx42, ft_movements, &game);
	mlx_loop(game.mlx42);
	free_images(&game);
	mlx_terminate(game.mlx42);
	free_split(game.map);
}
