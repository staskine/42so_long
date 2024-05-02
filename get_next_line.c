/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:28:11 by sataskin          #+#    #+#             */
/*   Updated: 2024/04/18 10:31:27 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_ret_strdel(char **string)
{
	free(*string);
	*string = NULL;
	return (NULL);
}

static char	*get_result(char **string)
{
	size_t		i;
	char		*temp;
	char		*line;

	i = 0;
	if (string[0][i] == '\0')
		return (ft_ret_strdel(string));
	while (string[0][i] != '\0' && string[0][i] != '\n')
		i++;
	if (string[0][i] == '\n' && string[0][i + 1] != '\0')
	{
		line = ft_substr(string[0], 0, i + 1);
		temp = *string;
		*string = ft_substr(temp, (i + 1), (ft_strlen(temp) - i));
		free(temp);
		if (!(*string) || !line)
		{
			free(line);
			return (ft_ret_strdel(string));
		}
		return (line);
	}
	line = ft_strdup(*string);
	ft_ret_strdel(string);
	return (line);
}

static char	*ft_strcompile(char **string, char *buf)
{
	char	*temp;

	if (*string == NULL)
	{
		*string = ft_strdup(buf);
		if (!(*string))
			return (NULL);
	}
	else
	{
		temp = *string;
		*string = ft_strjoin(temp, buf);
		free(temp);
		if (!(*string))
			return (NULL);
	}
	return (*string);
}

static char	*check_result(char **string, int ret)
{
	if (ret < 0)
		return (ft_ret_strdel(string));
	return (get_result(string));
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || fd > FD_SIZE || read(fd, buf, 0) < 0)
		return (ft_ret_strdel(&string));
	if (string != 0)
	{
		if (ft_strchr(string, '\n'))
			return (get_result(&string));
	}
	ret = read(fd, buf, BUFFER_SIZE);
	if ((ret == 0 && !string) || ret < 0)
		return (ft_ret_strdel(&string));
	while (ret > 0)
	{
		buf[ret] = '\0';
		string = ft_strcompile(&string, buf);
		if (!string)
			return (ft_ret_strdel(&string));
		if (ft_strchr(string, '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	return (check_result(&string, ret));
}
