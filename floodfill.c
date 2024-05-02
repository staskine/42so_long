/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:59:48 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 14:06:19 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fillmap(char **copy, t_node *game, int x, int y)
{
	if (y < 1 || y >= (game->y - 1) || x < 1 || x >= game->x
		|| copy[y][x] == 'F' || copy[y][x] == '1')
		return ;
	copy[y][x] = 'F';
	fillmap(copy, game, x - 1, y);
	fillmap(copy, game, x + 1, y);
	fillmap(copy, game, x, y - 1);
	fillmap(copy, game, x, y + 1);
}

void	floodfill(t_node *game)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = ft_ardub(game->map, game->y);
	fillmap(copy, game, game->p_x, game->p_y);
	while (copy[i])
	{
		j = 0;
		while (copy[i][j] != '\0')
		{
			if (copy[i][j] == 'E' || copy[i][j] == 'C')
			{
				free_split(copy);
				free_split(game->map);
				exit_none(5);
			}
			j++;
		}
		i++;
	}
	free_split(copy);
}
