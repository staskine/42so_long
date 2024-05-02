/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:17:52 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 14:06:31 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **array)
{
	size_t	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

void	free_images(t_node *game)
{
	if (game->image.col)
		mlx_delete_image(game->mlx42, game->image.col);
	if (game->image.p)
		mlx_delete_image(game->mlx42, game->image.p);
	if (game->image.wall)
		mlx_delete_image(game->mlx42, game->image.wall);
	if (game->image.exit)
		mlx_delete_image(game->mlx42, game->image.exit);
	if (game->image.floor)
		mlx_delete_image(game->mlx42, game->image.floor);
}

void	free_textures(t_node *game)
{
	if (game->image.col_t)
		mlx_delete_texture(game->image.col_t);
	if (game->image.p_t)
		mlx_delete_texture(game->image.p_t);
	if (game->image.wall_t)
		mlx_delete_texture(game->image.wall_t);
	if (game->image.exit_t)
		mlx_delete_texture(game->image.exit_t);
	if (game->image.floor_t)
		mlx_delete_texture(game->image.floor_t);
}

void	exit_mlx(char **map, t_node *game, char *str)
{
	free_split(map);
	free_textures(game);
	free_images(game);
	mlx_terminate(game->mlx42);
	write(2, "Error\n", 6);
	ft_putendl_fd(str, 2);
	exit (1);
}
