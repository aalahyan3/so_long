/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:24:10 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/23 17:15:52 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	idle_player(t_game *game)
{
	static int	frame_counter;
	static int	current_frame;
	int			frame_delay;

	frame_counter += 1;
	frame_delay = 30;
	if (frame_counter >= frame_delay)
	{
		frame_counter = 0;
		current_frame = current_frame + 1;
		if (current_frame >= 2)
			current_frame = 0;
	}
	game->sprites.player_l.current_frame = current_frame;
	game->sprites.player_r.current_frame = current_frame;
}

static void	run_player(t_game *game)
{
	static int	frame_counter;
	static int	current_frame;
	static int	stop_calibre;

	frame_counter += 1;
	stop_calibre += 1;
	if (stop_calibre > 15)
	{
		game->player.is_moving = false;
		stop_calibre = 0;
		return ;
	}
	if (frame_counter >= 3)
	{
		frame_counter = 0;
		current_frame = current_frame + 1;
		if (current_frame >= 2)
			current_frame = 0;
	}
	game->sprites.p_run_l .current_frame = current_frame;
	game->sprites.p_run_r.current_frame = current_frame;
}

static void	animate_enemies(t_game *game)
{
	static int	frame_counter;
	static int	current_frame;
	int			frame_delay;

	frame_counter += 1;
	frame_delay = 5;
	if (frame_counter >= frame_delay)
	{
		frame_counter = 0;
		current_frame = current_frame + 1;
		if (current_frame >= 2)
			current_frame = 0;
	}
	game->sprites.enemy.current_frame = current_frame;
}

static void	print_moves(t_game *game)
{
	char	*moves;
	char	moves_message[20];

	moves = ft_itoa(game->player.moves);
	if (!moves)
		clear_and_exit(game, ALLOC_FAIL, 20);
	ft_strlcpy(moves_message, "moves: ", 20);
	ft_strlcat(moves_message, moves, 20);
	mlx_string_put(game->vars.mlx, \
game->vars.window, 10, 10, 0xF8F800, moves_message);
	free(moves);
}

int	render_frame(t_game *game)
{
	static int	frames;

	frames += 1;
	if (frames >= 30)
	{
		move_enemies(game);
		frames = 0;
	}
	idle_player(game);
	run_player(game);
	animate_enemies(game);
	render_frame_2(game);
	print_moves(game);
	return (0);
}
