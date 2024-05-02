/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:15:04 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 14:02:57 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_image(t_node *game)
{
	game->image.p_t = mlx_load_png("./sprites/player.png");
	if (!game->image.p_t)
		exit_mlx(game->map, game, "player texture not loaded");
	game->image.wall_t = mlx_load_png("./sprites/wall.png");
	if (!game->image.wall_t)
		exit_mlx(game->map, game, "wall texture not loaded");
	game->image.floor_t = mlx_load_png("./sprites/floor.png");
	if (!game->image.floor_t)
		exit_mlx(game->map, game, "floor texture not loaded");
	game->image.col_t = mlx_load_png("./sprites/collectible.png");
	if (!game->image.col_t)
		exit_mlx(game->map, game, "collectible texture not loaded");
	game->image.exit_t = mlx_load_png("./sprites/exit.png");
	if (!game->image.exit_t)
		exit_mlx(game->map, game, "exit texture not loaded");
}

void	get_tile_size(t_node *game)
{
	int	x_size;
	int	y_size;

	x_size = (WINDOW_WIDTH / game->x);
	y_size = (WINDOW_HEIGHT / game->y);
	if (x_size > y_size)
		game->tile_size = y_size;
	else
		game->tile_size = x_size;
}

static void	resize_image(t_node *game)
{
	int	t_s;

	t_s = game->tile_size;
	if (mlx_resize_image(game->image.p, t_s, t_s) == 0)
		exit_mlx(game->map, game, "Resize failed");
	if (mlx_resize_image(game->image.floor, t_s, t_s) == 0)
		exit_mlx(game->map, game, "Resize failed");
	if (mlx_resize_image(game->image.col, t_s, t_s) == 0)
		exit_mlx(game->map, game, "Resize failed");
	if (mlx_resize_image(game->image.wall, t_s, t_s) == 0)
		exit_mlx(game->map, game, "Resize failed");
	if (mlx_resize_image(game->image.exit, t_s, t_s) == 0)
		exit_mlx(game->map, game, "Resize failed");
}

void	initialize_images(t_node *game)
{
	load_image(game);
	game->image.p = mlx_texture_to_image(game->mlx42, game->image.p_t);
	if (!game->image.p)
		exit_mlx(game->map, game, "Texture to image for player failed");
	game->image.wall = mlx_texture_to_image(game->mlx42, game->image.wall_t);
	if (!game->image.wall)
		exit_mlx(game->map, game, "Texture to image for wall failed");
	game->image.floor = mlx_texture_to_image(game->mlx42, game->image.floor_t);
	if (!game->image.floor)
		exit_mlx(game->map, game, "Texture to image for floor failed");
	game->image.col = mlx_texture_to_image(game->mlx42, game->image.col_t);
	if (!game->image.col)
		exit_mlx(game->map, game, "Texture to image for collectible failed");
	game->image.exit = mlx_texture_to_image(game->mlx42, game->image.exit_t);
	if (!game->image.exit)
		exit_mlx(game->map, game, "Texture to image for exit failed");
	free_textures(game);
	resize_image(game);
}
