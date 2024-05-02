/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:43:05 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 13:52:55 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_dir(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		exit_none(1);
	}
	close(fd);
}

void	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		exit_none(1);
	}
	close(fd);
}

void	check_file_format(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 4)
		exit_none(2);
	if ((ft_strcmp(&str[i - 4], ".ber")) != 0)
		exit_none(2);
}

void	check_valid(char *file)
{
	check_file_format(file);
	check_dir(file);
	check_file(file);
}
