/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:06:08 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 14:09:02 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player(t_node *game, int x, int y)
{
	game->p_x = x;
	game->p_y = y;
}

static void	set_exit(t_node *game, int x, int y)
{
	game->exit_x = x;
	game->exit_y = y;
}

void	check_tandb(t_node *game, int i)
{
	int	len;

	len = 0;
	while (game->map[i][len] != '\0')
	{
		if (game->map[i][len] != '1')
		{
			free_split(game->map);
			exit_none(4);
		}
		len++;
	}
}

void	check_rest(t_node *game, int i)
{
	int	len;

	len = ft_strlen(game->map[i]) - 1;
	if (game->map[i][0] != '1' || game->map[i][len] != '1')
	{
		free_split(game->map);
		exit_none(4);
	}
	len = 0;
	while (game->map[i][len] != '\0')
	{
		if (game->map[i][len] == 'P')
			set_player(game, len, i);
		if (game->map[i][len] == 'E')
			set_exit(game, len, i);
		if (game->map[i][len] == 'C')
			game->coins++;
		len++;
	}
	game->og_coins = game->coins;
}
