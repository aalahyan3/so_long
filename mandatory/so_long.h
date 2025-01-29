/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:53:01 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/26 17:19:06 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"

# define ESC 53
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define RED    "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREEN  "\033[1;32m"
# define RESET "\033[0m"
# define INV_ARGS_ERR "Invalid Arguments: usage ./so_long map.ber"
# define ERR_OP_FILE "Error opening File!"
# define INV_EXT "Invalid extension : only <.ber> is allowed"
# define MLX_INIT_FAIL "mlx_init() failed to connect to X11 Server"
# define ALLOC_FAIL "malloc() failed at some point:'echo $?' to debug!"
# define NB_P_ERR "one player position 'P' must be provided!"
# define NB_C_ERR "at least one collectible 'C' must be provided!"
# define NB_E_ERR "one Exit position 'E' must be provided!"
# define MAP_SURR_WALL "map must be surrounded by walls"
# define INV_MAP_DIM "Invalid map dimensions it must \
be recttangular and max size is 50 * 25"
# define INV_PATH "There is no way the player can collect all keys and exit!"
# define LOAD_ERROR "Failed to load textures or sprites"
# define ERR_OP_WIN "Error Opening Window!"
# define SIZE_ERROR "The size of images must be 50px x 50px"
# define INV_MAP_COMP "Invalid map components!"
# define WIN_MESSAGE "===================\n= CONGRATILATIONS =\
\n===================\n"

struct s_vars
{
	void	*mlx;
	void	*window;
	int		window_h;
	int		window_w;
};

struct	s_player
{
	int		x;
	int		y;
	int		moves;
	int		collected;
	bool	face_right;
};

typedef struct s_map
{
	char	**map_arr;
	int		width;
	int		height;
	int		nb_c;
	int		nb_p;
	int		nb_e;
}	t_map;

struct	s_img
{
	void	*ptr;
	int		height;
	int		width;
};

struct	s_textures
{
	struct s_img	empty;
	struct s_img	wall;
	struct s_img	collect;
	struct s_img	p_l;
	struct s_img	p_r;
	struct s_img	exit;
};

typedef struct s_game
{
	struct s_vars		vars;
	struct s_player		player;
	t_map				map;
	struct s_textures	textures;
}	t_game;

int		main(int ac, char **av);
void	exit_code(char *message, int code);
void	file_validation(char *filename);
void	map_parsing(t_game *game, char *filename);
void	free_map_array(char **arr);
void	map_parsing(t_game *game, char *filename);
void	map_parsing_2(t_game *game);
void	clear_and_exit(t_game *game, char *message, int code);
void	clear_all(t_game *game);
bool	valid_path(t_game *game);
void	load_data(t_game *game);
int		close_window(void *param);
void	start_game(t_game *game);
int		render_frame(t_game *game);
void	game_over(t_game *game);

#endif