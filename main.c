/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:55:37 by sataskin          #+#    #+#             */
/*   Updated: 2024/04/18 10:35:32 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
	{
		ft_putstr_fd(ERR_ARG, 2);
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr_fd(ERR_MAP, 2);
		return (1);
	}
	so_long(argv[1]);
	return (0);
}
