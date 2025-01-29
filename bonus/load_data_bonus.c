/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:16:22 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/23 15:42:27 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_textures(t_game *game)
{
	game->textures.collect.ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/textures/collect.xpm", &game->textures.collect.width, \
	&game->textures.collect.height);
	game->textures.empty.ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/textures/empty.xpm", &game->textures.empty.width, \
	&game->textures.empty.height);
	game->textures.wall.ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/textures/wall.xpm", &game->textures.wall.width, \
	&game->textures.wall.height);
	if (!game->textures.collect.ptr || !game->textures.empty.ptr || \
	!game->textures.wall.ptr)
		clear_and_exit(game, LOAD_ERROR, 10);
}

static void	load_sprites_1(t_game *game)
{
	game->sprites.enemy.frame[0].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/enemy_0.xpm", &game->sprites.enemy.frame[0].width, \
	&game->sprites.enemy.frame[0].height);
	game->sprites.enemy.frame[1].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/enemy_1.xpm", &game->sprites.enemy.frame[1].width, \
	&game->sprites.enemy.frame[1].height);
	game->sprites.player_l.frame[0].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/player_l_0.xpm", &game->sprites.player_l.frame[0].width, \
	&game->sprites.player_l.frame[0].height);
	game->sprites.player_l.frame[1].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/player_l_1.xpm", &game->sprites.player_l.frame[1].width, \
	&game->sprites.player_l.frame[1].height);
	game->sprites.player_r.frame[0].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/player_r_0.xpm", &game->sprites.player_r.frame[0].width, \
	&game->sprites.player_r.frame[0].height);
	game->sprites.player_r.frame[1].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/player_r_1.xpm", &game->sprites.player_r.frame[1].width, \
	&game->sprites.player_r.frame[1].height);
	if (!game->sprites.enemy.frame[0].ptr || \
	!game->sprites.enemy.frame[1].ptr || \
	!game->sprites.player_l.frame[0].ptr || \
	!game->sprites.player_l.frame[1].ptr || \
	!game->sprites.player_r.frame[0].ptr || \
	!game->sprites.player_r.frame[1].ptr)
		clear_and_exit(game, LOAD_ERROR, 10);
}

static void	load_sprites_2(t_game *game)
{
	game->sprites.p_run_l.frame[0].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/p_run_l_0.xpm", &game->sprites.p_run_l.frame[0].width, \
	&game->sprites.p_run_l.frame[0].height);
	game->sprites.p_run_l.frame[1].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/p_run_l_1.xpm", &game->sprites.p_run_l.frame[1].width, \
	&game->sprites.p_run_l.frame[1].height);
	game->sprites.p_run_r.frame[0].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/p_run_r_0.xpm", &game->sprites.p_run_r.frame[0].width, \
	&game->sprites.p_run_r.frame[0].height);
	game->sprites.p_run_r.frame[1].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/p_run_r_1.xpm", &game->sprites.p_run_r.frame[1].width, \
	&game->sprites.p_run_r.frame[1].height);
	game->sprites.exit.frame[0].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/exit_0.xpm", &game->sprites.exit.frame[0].width, \
	&game->sprites.exit.frame[0].height);
	game->sprites.exit.frame[1].ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"bonus/sprites/exit_1.xpm", &game->sprites.exit.frame[1].width, \
	&game->sprites.exit.frame[1].height);
	if (!game->sprites.p_run_l.frame[0].ptr || \
!game->sprites.p_run_l.frame[1].ptr || !game->sprites.p_run_r.frame[0].ptr || \
!game->sprites.p_run_r.frame[1].ptr || !game->sprites.exit.frame[0].ptr || \
	!game->sprites.exit.frame[1].ptr)
		clear_and_exit(game, LOAD_ERROR, 10);
}

static bool	verify_images_size(struct s_textures textures, \
struct s_sprites sprites)
{
	if (textures.collect.height != 50 || textures.collect.width != 50 || \
textures.empty.height != 50 || textures.empty.width != 50 || \
textures.wall.height != 50 || textures.wall.width != 50 || \
sprites.enemy.frame[0].height != 50 || sprites.enemy.frame[0].width != 50 || \
sprites.enemy.frame[1].height != 50 || sprites.enemy.frame[1].width != 50 || \
sprites.player_l.frame[0].height != 50 || \
sprites.player_l.frame[0].width != 50 || \
sprites.player_l.frame[1].height != 50 || \
sprites.player_l.frame[1].width != 50 || \
sprites.player_r.frame[0].height != 50 || \
sprites.player_r.frame[0].width != 50 || \
sprites.player_r.frame[1].height != 50 || \
sprites.player_r.frame[1].width != 50 || \
sprites.p_run_l.frame[0].height != 50 || \
sprites.p_run_l.frame[0].width != 50 || \
sprites.p_run_l.frame[1].height != 50 || \
sprites.p_run_l.frame[1].width != 50 || \
sprites.p_run_r.frame[0].height != 50 || \
sprites.p_run_r.frame[0].width != 50 || \
sprites.p_run_r.frame[1].height != 50 || \
sprites.p_run_r.frame[1].width != 50 || \
sprites.exit.frame[0].height != 50 || sprites.exit.frame[0].width != 50 || \
sprites.exit.frame[1].height != 50 || sprites.exit.frame[1].width != 50)
		return (false);
	return (true);
}

void	load_data(t_game *game)
{
	load_textures(game);
	load_sprites_1(game);
	load_sprites_2(game);
	if (!verify_images_size(game->textures, game->sprites))
		clear_and_exit(game, SIZE_ERROR, 10);
}
