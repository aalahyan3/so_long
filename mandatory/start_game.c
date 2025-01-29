/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:04:00 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/26 17:31:24 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_game *game)
{
	ft_printf(GREEN WIN_MESSAGE RESET);
	clear_all(game);
	exit(0);
}

static void	move_player(t_game *game, int dx, int dy)
{
	if (game->map.map_arr[game->player.y + dy][game->player.x + dx] == '1')
		return ;
	if (game->map.map_arr[game->player.y + dy][game->player.x + dx] == 'E')
	{
		if (game->player.collected == game->map.nb_c)
		{
			ft_printf(YELLOW"[%d Moves] from (%d, %d) to (%d, %d)\n"RESET, \
			game->player.moves + 1, game->player.x, \
			game->player.y, game->player.x + dx, game->player.y + dy);
			game_over(game);
		}
		return ;
	}
	if (game->map.map_arr[game->player.y + dy][game->player.x + dx] == 'C')
		game->player.collected += 1;
	game->map.map_arr[game->player.y + dy][game->player.x + dx] = 'P';
	game->map.map_arr[game->player.y][game->player.x] = '0';
	game->player.x += dx;
	game->player.y += dy;
	game->player.moves += 1;
	ft_printf(YELLOW"[%d Moves] from (%d, %d) to (%d, %d)\n"RESET, \
	game->player.moves, game->player.x - dx, \
	game->player.y - dy, game->player.x, game->player.y);
}

static int	key_monitoring(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == UP)
		move_player(game, 0, -1);
	else if (keycode == DOWN)
		move_player(game, 0, 1);
	else if (keycode == RIGHT)
	{
		game->player.face_right = true;
		move_player(game, 1, 0);
	}
	else if (keycode == LEFT)
	{
		game->player.face_right = false;
		move_player(game, -1, 0);
	}
	return (0);
}

void	start_game(t_game *game)
{
	game->vars.window = mlx_new_window(game->vars.mlx, game->map.width * 50, \
	game->map.height * 50, "so_long");
	if (!game->vars.window)
		clear_and_exit(game, ERR_OP_WIN, 11);
	mlx_hook(game->vars.window, 2, 0, key_monitoring, game);
	mlx_hook(game->vars.window, 17, 0, close_window, game);
	mlx_loop_hook(game->vars.mlx, render_frame, game);
	mlx_loop(game->vars.mlx);
}
