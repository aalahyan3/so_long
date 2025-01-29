/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:24:10 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/26 16:40:15 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game *game, void *ptr, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx, \
	game->vars.window, ptr, x * 50, y * 50);
}

static void	render_frame_2(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map.map_arr[++y])
	{
		x = -1;
		while (game->map.map_arr[y][++x])
		{
			put_image(game, game->textures.empty.ptr, x, y);
			if (game->map.map_arr[y][x] == '1')
				put_image(game, game->textures.wall.ptr, x, y);
			else if (game->map.map_arr[y][x] == 'C')
				put_image(game, game->textures.collect.ptr, x, y);
			else if (game->map.map_arr[y][x] == 'E')
				put_image(game, game->textures.exit.ptr, x, y);
			else if (game->map.map_arr[y][x] == 'P')
			{
				if (game->player.face_right)
					put_image(game, game->textures.p_r.ptr, x, y);
				else
					put_image(game, game->textures.p_l.ptr, x, y);
			}
		}
	}
}

int	render_frame(t_game *game)
{
	render_frame_2(game);
	return (0);
}
