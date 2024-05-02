/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:02:36 by sataskin          #+#    #+#             */
/*   Updated: 2024/05/02 11:54:45 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WINDOW_WIDTH  1920
# define WINDOW_HEIGHT  1080

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include "get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h> // Delete me

# define ERR_MAP "Error\nToo many arguments\n"
# define ERR_ARG "Error\nGive a second argument\n"

typedef struct s_game
{
	mlx_image_t		*p;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*col;
	mlx_image_t		*exit;
	mlx_texture_t	*p_t;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*floor_t;
	mlx_texture_t	*col_t;
	mlx_texture_t	*exit_t;
}	t_game;

typedef struct s_node
{
	int				coins;
	int				og_coins;
	int				exit_x;
	int				exit_y;
	int				x;
	int				y;
	int				moves;
	int				tile_size;
	int				p_x;
	int				p_y;
	char			**map;
	void			*mlx42;
	t_game			image;
}	t_node;

/*		FOR VALIDATING FILE		*/
void	check_dir(char *file);
void	check_file(char *file);
void	check_file_format(char *str);
void	check_valid(char *file);

/*		MAIN FUNCTIONS			*/
void	so_long(char *file);

/*		FOR MAKING MAP			*/
void	initialize_map(t_node *game, char *file);
char	*get_line(int fd);
char	**get_map(int fd);

/*		FOR MAP PARSING			*/
void	parse_map(t_node *game);
void	check_tandb(t_node *game, int i);
void	check_rest(t_node *game, int i);
void	floodfill(t_node *game);
void	fillmap(char **copy, t_node *game, int x, int y);

/*		FOR ERROR HANDLING		*/
void	exit_none(int none);
void	exit_str(char *str, int num);
void	exit_dstr(char *s1, char *s2, int num);
void	exit_mlx(char **map, t_node *game, char *str);

/*		FREE FUNCTIONS			*/
void	free_split(char **array);
void	free_images(t_node *game);
void	free_textures(t_node *game);

/*		UTIL FUNCTIONS			*/
int		count_char(char *str, char c);
void	check_char(char *str);
char	**ft_ardub(char **array, int i);

/*		FOR DELETING AFTER		*/
void	read_map(char **map);
void	print_struct(t_node *game);

/*		FOR IMAGES				*/
void	initialize_images(t_node *game);
void	get_tile_size(t_node *game);
void	add_collectibles(t_node *game);
void	add_floor(t_node *game);
void	add_walls(t_node *game);
void	image_to_window(t_node *game);

/*		FOR GAME				*/
void	ft_movements(mlx_key_data_t keydata, void *data);
void	delete_collectible(t_node *game, int y, int x);
void	check_status(t_node *game);
void	delete_collectible(t_node *game, int y, int x);

#endif