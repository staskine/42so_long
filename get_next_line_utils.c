/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:43:52 by sataskin          #+#    #+#             */
/*   Updated: 2023/12/20 13:45:34 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	end;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	end = 0;
	while (len > 0)
	{
		str[end] = s[start];
		end++;
		start++;
		len--;
	}
	str[end] = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;
	int		index;

	len = ft_strlen(src);
	index = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (index < len)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;	

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*dest;
	unsigned int	i_s;
	unsigned int	i_dest;

	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	i_s = 0;
	i_dest = 0;
	if (!dest)
		return (NULL);
	while (s1[i_dest] != '\0')
	{
		dest[i_dest] = s1[i_dest];
		i_dest++;
	}
	while (s2[i_s] != '\0')
	{
		dest[i_dest] = s2[i_s];
		i_dest++;
		i_s++;
	}
	dest[i_dest] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	u_c;
	unsigned char	*s;

	i = 0;
	u_c = (unsigned char)c;
	s = (unsigned char *)str;
	while (s[i] != '\0' && s[i] != u_c)
		i++;
	if (s[i] == u_c)
		return ((char *)&str[i]);
	return (NULL);
}
