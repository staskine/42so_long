/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:42:29 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 14:08:43 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_line(int fd)
{
	char	*line;
	char	*str;
	char	*temp;

	line = ft_strdup("");
	if (!line)
		exit_none(3);
	while (1)
	{
		str = get_next_line(fd);
		temp = line;
		if (str == NULL)
			break ;
		if (ft_strcmp(str, "\n") == 0)
			exit_dstr(line, str, 4);
		line = ft_strjoin(temp, str);
		if (!temp)
			exit_str(str, 3);
		free(temp);
		free(str);
	}
	if (str)
		free(str);
	check_char(line);
	return (line);
}

char	**get_map(int fd)
{
	char	**map;
	char	*line;

	line = get_line(fd);
	if (line[ft_strlen(line) - 1] == '\n')
		exit_str(line, 4);
	if (count_char(line, 'P') != 1
		|| count_char(line, 'E') != 1)
		exit_str(line, 4);
	if (count_char(line, 'C') < 1)
		exit_str(line, 4);
	map = ft_split(line, '\n');
	if (!map)
		exit_str(line, 3);
	free(line);
	return (map);
}
