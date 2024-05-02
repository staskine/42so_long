/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:46:06 by sataskin          #+#    #+#             */
/*   Updated: 2024/04/18 12:12:59 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_none(int none)
{
	if (none == 1)
		ft_putstr_fd("Error\nCheck file\n", 2);
	if (none == 2)
		ft_putstr_fd("Error\nFile name is in wrong format\n", 2);
	if (none == 3)
		ft_putstr_fd("Error\nMALLOC FAIL\n", 2);
	if (none == 4)
		ft_putstr_fd("Error\nInvalid map\n", 2);
	if (none == 5)
		ft_putstr_fd("Error\nNo valid path\n", 2);
	if (none == 6)
		ft_putstr_fd("Error\nMap not a rectangle", 2);
	exit (1);
}

void	exit_str(char *str, int num)
{
	free(str);
	exit_none(num);
}

void	exit_dstr(char *s1, char *s2, int num)
{
	if (s1)
		free(s1);
	free(s2);
	exit_none(num);
}
