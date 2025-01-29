/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:00:39 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/22 17:49:14 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_image(t_game *game, void *ptr, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx, \
	game->vars.window, ptr, x * 50, y * 50);
}

static void	draw_exit(t_game *game, int x, int y)
{
	if (game->player.collected == game->map.nb_c)
		put_image(game, game->sprites.exit.frame[1].ptr, x, y);
	else
		put_image(game, game->sprites.exit.frame[0].ptr, x, y);
}

static void	draw_player(t_game *game, int x, int y)
{
	if (game->player.face_right)
	{
		if (game->player.is_moving)
			put_image(game, \
game->sprites.p_run_r.frame[game->sprites.p_run_r.current_frame].ptr, x, y);
		else
			put_image(game, \
game->sprites.player_r.frame[game->sprites.player_r.current_frame].ptr, x, y);
	}
	else
	{
		if (game->player.is_moving)
			put_image(game, \
game->sprites.p_run_l.frame[game->sprites.p_run_l.current_frame].ptr, x, y);
		else
			put_image(game, \
game->sprites.player_l.frame[game->sprites.player_l.current_frame].ptr, x, y);
	}
}

void	render_frame_2(t_game *game)
{
	int	y;
	int	x;
	int	ch;

	y = -1;
	while (game->map.map_arr[++y])
	{
		x = -1;
		while (game->map.map_arr[y][++x])
		{
			ch = game->map.map_arr[y][x];
			put_image(game, game->textures.empty.ptr, x, y);
			if (ch == '1')
				put_image(game, game->textures.wall.ptr, x, y);
			else if (ch == 'C')
				put_image(game, game->textures.collect.ptr, x, y);
			else if (ch == 'X')
				put_image(game, \
game->sprites.enemy.frame[game->sprites.enemy.current_frame].ptr, x, y);
			else if (ch == 'E')
				draw_exit(game, x, y);
			else if (ch == 'P')
				draw_player(game, x, y);
		}
	}
}
