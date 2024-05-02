/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:15:15 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 13:59:33 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_mapformat(t_node *game)
{
	int	i;

	i = game->y - 1;
	while (i > -1)
	{
		if (i == (game->y - 1) || i == 0)
			check_tandb(game, i);
		else
			check_rest(game, i);
		i--;
	}
}

static void	check_lines(t_node *game)
{
	int	len;
	int	i;

	len = (int)ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i] != NULL)
	{
		if (len != (int)ft_strlen(game->map[i]))
		{
			free_split(game->map);
			exit_none(4);
		}
		i++;
	}
	game->x = len;
	game->y = i;
	if (game->x < 3 || game->y < 3 || (len * (i) < 15))
	{
		free_split(game->map);
		exit_none(4);
	}
}

void	parse_map(t_node *game)
{
	check_lines(game);
	check_mapformat(game);
	floodfill(game);
}
