/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:31:49 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 13:59:18 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_node *game, int x, int y)
{
	char	*str;

	if (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
			delete_collectible(game, y, x);
		game->image.p->instances[0].y -= game->tile_size;
		game->p_y -= 1;
		game->moves++;
		str = ft_itoa(game->moves);
		ft_putstr_fd("Moves : ", 1);
		ft_putendl_fd(str, 1);
		free(str);
	}
	check_status(game);
}

static void	move_down(t_node *game, int x, int y)
{
	char	*str;

	if (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
			delete_collectible(game, y, x);
		game->image.p->instances[0].y += game->tile_size;
		game->p_y += 1;
		game->moves++;
		str = ft_itoa(game->moves);
		ft_putstr_fd("Moves : ", 1);
		ft_putendl_fd(str, 1);
		free(str);
	}
	check_status(game);
}

static void	move_right(t_node *game, int x, int y)
{
	char	*str;

	if (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
			delete_collectible(game, y, x);
		game->image.p->instances[0].x += game->tile_size;
		game->p_x += 1;
		game->moves++;
		str = ft_itoa(game->moves);
		ft_putstr_fd("Moves : ", 1);
		ft_putendl_fd(str, 1);
		free(str);
	}
	check_status(game);
}

static void	move_left(t_node *game, int x, int y)
{
	char	*str;

	if (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
			delete_collectible(game, y, x);
		game->image.p->instances[0].x -= game->tile_size;
		game->p_x -= 1;
		game->moves++;
		str = ft_itoa(game->moves);
		ft_putstr_fd("Moves : ", 1);
		ft_putendl_fd(str, 1);
		free(str);
	}
	check_status(game);
}

void	ft_movements(mlx_key_data_t keydata, void *data)
{
	t_node	*game;

	game = (t_node *)data;
	if (mlx_is_key_down(game->mlx42, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx42);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game, game->p_x, game->p_y - 1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game, game->p_x, game->p_y + 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game, game->p_x + 1, game->p_y);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game, game->p_x - 1, game->p_y);
}
