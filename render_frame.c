/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:51:24 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/06 20:01:21 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static int close_window(void *param)
{
	clear_game(param);
	exit(0);
}

static void game_over(t_game *game, bool win)
{
	int	x;
	int	y;

	x = game->vars.window.width / 2 - game->textures.congrats.width / 2;
	y = game->vars.window.height / 2 - game->textures.congrats.height / 2;
	mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.empty.img, game->player.x * game->tile_size, game->player.y * game->tile_size);
	if (win)
		mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.congrats.img,x , y);
}

static void	move_player(t_game *game, int to_x, int to_y)
{
	if (game->map.map_array[to_y][to_x] == '1' || game->game_over)
		return ;
	else if (game->map.map_array[to_y][to_x] == 'E')
	{
		if (game->collected == game->map.nb_collect)
		{
			game_over(game, true);
			mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.exit.img, to_x * game->tile_size, to_y * game->tile_size);
			game->game_over = true;
			return ;
		}
		else
			return ;
	}
	else if (game->map.map_array[to_y][to_x] == 'C')
	{
		game->collected += 1;
		game->map.map_array[to_y][to_x] = '0';
	}
	mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.empty.img, game->player.x * game->tile_size, game->player.y * game->tile_size);
	if (game->player.face_right)
		mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.player_right.img, to_x * game->tile_size, to_y * game->tile_size);
	else
		mlx_put_image_to_window(game->vars.mlx, game->vars.window.window, game->textures.player_left.img, to_x * game->tile_size, to_y * game->tile_size);
	game->player.moves += 1;
	ft_printf("[%d moves]: player moved from (%d, %d) to (%d, %d)\n", game->player.moves, game->player.x, game->player.y, to_x, to_y);
	game->player.x = to_x;
	game->player.y = to_y;
}

static int	apply_action(int key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	else if (key == UP)
		move_player(game, game->player.x, game->player.y - 1);
	else if (key == DOWN)
		move_player(game, game->player.x, game->player.y + 1);
	else if (key == RIGHT)
	{
		game->player.face_right = true;
		move_player(game, game->player.x + 1, game->player.y);
	}
	else if (key == LEFT)
	{
		game->player.face_right = false;
		move_player(game, game->player.x - 1, game->player.y);
	}
	return (0);
}


void	render_frame(t_game *game)
{
	mlx_hook(game->vars.window.window, CROSS, 0, close_window, game);
	mlx_key_hook(game->vars.window.window, apply_action, game);

}