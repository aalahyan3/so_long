/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:29:41 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/07 20:38:45 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_data(t_game *game)
{
	int	surface;

	surface = game->map.height * game->map.width;
	if (surface < 800)
	{
		game->textures.collect.path = "textures/large_collect.xpm";
		game->textures.empty.path = "textures/large_empty.xpm";
		game->textures.wall.path = "textures/large_wall.xpm";
		game->textures.exit.path = "textures/large_exit.xpm";
		game->textures.player_left.path = "textures/large_player_left.xpm";
		game->textures.player_right.path = "textures/large_player_right.xpm";
		game->tile_size = 50;
		game->vars.window.height = 50 * game->map.height;
		game->vars.window.width = 50 * game->map.width;
	}
	else
	{

		game->textures.collect.path = "textures/small_collect.xpm";
		game->textures.empty.path = "textures/small_empty.xpm";
		game->textures.wall.path = "textures/small_wall.xpm";
		game->textures.exit.path = "textures/small_exit.xpm";
		game->textures.player_left.path = "textures/small_player_left.xpm";
		game->textures.player_right.path = "textures/small_player_right.xpm";
		game->tile_size = 25;
		game->vars.window.height = 25 * game->map.height;
		game->vars.window.width = 25 * game->map.width;
	}
	game->textures.congrats.path = "textures/congrats.xpm";
}

static void	init_data_2(t_game *game)
{
	game->textures.collect.img = mlx_xpm_file_to_image(game->vars.mlx, game->textures.collect.path, &game->textures.collect.width, &game->textures.collect.height);
	game->textures.empty.img = mlx_xpm_file_to_image(game->vars.mlx, game->textures.empty.path, &game->textures.empty.width, &game->textures.empty.height);
	game->textures.wall.img = mlx_xpm_file_to_image(game->vars.mlx, game->textures.wall.path, &game->textures.wall.width, &game->textures.wall.height);
	game->textures.player_left.img = mlx_xpm_file_to_image(game->vars.mlx, game->textures.player_left.path, &game->textures.player_left.width, &game->textures.player_left.height);
	game->textures.player_right.img = mlx_xpm_file_to_image(game->vars.mlx, game->textures.player_right.path, &game->textures.player_right.width, &game->textures.player_right.height);
	game->textures.exit.img = mlx_xpm_file_to_image(game->vars.mlx, game->textures.exit.path, &game->textures.exit.width, &game->textures.exit.height);
	game->textures.congrats.img = mlx_xpm_file_to_image(game->vars.mlx, game->textures.congrats.path, &game->textures.congrats.width, &game->textures.congrats.height);
	if (!game->textures.collect.img || \
		!game->textures.empty.img || \
		!game->textures.exit.img || \
		!game->textures.player_left.img || \
		!game->textures.player_right.img || \
		!game->textures.congrats.img ||
		!game->textures.exit.img)
		{
			free_textures(game);
			exit_code(ERR_MLX_FAIL, 9);
		}
	game->player.x  = game->map.player_x;
	game->player.y = game->map.player_y;
	game->player.moves = 0;
	game->collected = 0;
	game->player.face_right = true;
}

static void	add_element(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.empty.img, x * game->tile_size, y * game->tile_size);
	if (game->map.map_array[y][x] == '1')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.wall.img, x * game->tile_size, y * game->tile_size);
	else if (game->map.map_array[y][x] == 'C')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.collect.img, x * game->tile_size, y * game->tile_size);
	else if (game->map.map_array[y][x] == 'P')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.player_right.img, x * game->tile_size, y * game->tile_size);
	else if (game->map.map_array[y][x] == 'E')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.exit.img, x * game->tile_size, y * game->tile_size);
}
void	render_game(t_game *game)
{
	int	x;
	int	y;

	init_data(game);
	init_data_2(game);
	game->vars.window.window = mlx_new_window(game->vars.mlx, game->vars.window.width, game->vars.window.height, "s0long");
	y = 0;
	while ( y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			add_element(game, x, y);
			x++;
		}
		y++;
	}
}