/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:16:22 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/26 16:39:36 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_textures(t_game *game)
{
	game->textures.collect.ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"mandatory/textures/collect.xpm", &game->textures.collect.width, \
	&game->textures.collect.height);
	game->textures.empty.ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"mandatory/textures/empty.xpm", &game->textures.empty.width, \
	&game->textures.empty.height);
	game->textures.wall.ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"mandatory/textures/wall.xpm", &game->textures.wall.width, \
	&game->textures.wall.height);
	game->textures.exit.ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"mandatory/textures/exit.xpm", &game->textures.exit.width, \
	&game->textures.exit.height);
	game->textures.p_l.ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"mandatory/textures/p_left.xpm", &game->textures.p_l.width, \
	&game->textures.p_l.height);
	game->textures.p_r.ptr = mlx_xpm_file_to_image(game->vars.mlx, \
	"mandatory/textures/p_right.xpm", &game->textures.p_r.width, \
	&game->textures.p_r.height);
	if (!game->textures.collect.ptr || !game->textures.empty.ptr || \
	!game->textures.wall.ptr || !game->textures.exit.ptr || \
	!game->textures.p_l.ptr || !game->textures.p_r.ptr)
		clear_and_exit(game, LOAD_ERROR, 10);
}

static bool	verify_images_size(struct s_textures textures)
{
	if (textures.collect.height != 50 || textures.collect.width != 50 || \
textures.empty.height != 50 || textures.empty.width != 50 || \
textures.wall.height != 50 || textures.wall.width != 50 || \
textures.exit.height != 50 || textures.exit.width != 50 || \
textures.p_l.height != 50 || textures.p_l.width != 50 || \
textures.p_r.height != 50 || textures.p_r.width != 50)
		return (false);
	return (true);
}

void	load_data(t_game *game)
{
	load_textures(game);
	if (!verify_images_size(game->textures))
		clear_and_exit(game, SIZE_ERROR, 10);
}
