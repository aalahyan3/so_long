/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:17:40 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/06 19:44:27 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
 // Includes
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"
// structs

typedef struct s_map
{
	char	**map_array;
	int		width;
	int		height;
	int		nb_collect;
	int		nb_exits;
	int		nb_player;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		line_height;
	int		endian;
	int		width;
	int		height;
	char	*path;
}	t_img;

typedef struct s_window
{
	void 	*window;
	int		height;
	int		width;
}	t_window;

typedef struct s_vars
{
	void		*mlx;
	t_window	window;
}	t_vars;


typedef struct s_player
{
	int		x;
	int		y;
	int		collected;
	bool	face_right;
	int		moves;
}	t_player;

typedef struct s_textures
{
	t_img	wall;
	t_img	empty;
	t_img	player_right;
	t_img	player_left;
	t_img	collect;
	t_img	exit;
	t_img	congrats;
}	t_textures;
typedef struct s_game
{
	t_vars		vars;
	t_map		map;
	t_player	player;
	t_textures	textures;
	int			tile_size;
	int		collected;
	bool	game_over;
	bool	exit_reached;
}	t_game;


// macros
# define INVALID_ARGS_MESSAGE	"Error: Invalid Arguments: usage ./so_long map.ber !"
# define INVALID_EXT_MESSAGE	"Error: Invalid Extention, Only <.ber> is allowed!"
# define ERR_OP_FILE			"Error: Either the file doesn't exist or it's empty"
# define ALLOC_FAIL				"Error: Memory Allocation failure, try smaller map !"
# define INV_DIMENTIONS			"Error: Map dimentions is invalid, it must be rectangular and max size is 100 * 50"
# define INV_COMPONENTS			"Error: Invalid map components: only one 'E' and 'P', at least one 'C'!"
# define MAP_NOT_SURR_BY_WALLS	"Error: The Map must be surrounded by walls !"
# define MAP_PATH_ERR			"Error: There is no way the player can reach all Collectibles and Exit!"
# define ERR_MLX_INIT			"Error: Mlx initialization failed !"
# define ERR_MLX_FAIL			"Error: Mlx failed to do an action !"
# define ESC 53
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define CROSS 17

//prototypes
int		main(int ac, char **av);
void	exit_code(char *message, int code);
t_map	parse_map(char *filename);
void	free_map_array(char **map);
void	map_validation(t_map *map);
bool	valid_path(t_map *map);
void	render_game(t_game *game); 
void	free_textures(t_game *game);
void	render_frame(t_game *game);
void	clear_game(void *param);


#endif