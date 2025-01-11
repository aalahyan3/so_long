/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:15:41 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/06 19:06:04 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_array(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i] != NULL)
	{
		
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_textures(t_game *game)
{
	if (!game)
		return ;
	if (game->textures.collect.img)
		mlx_destroy_image(game->vars.mlx, game->textures.collect.img);
	if (game->textures.empty.img)
		mlx_destroy_image(game->vars.mlx, game->textures.empty.img);
	if (game->textures.wall.img)
		mlx_destroy_image(game->vars.mlx, game->textures.wall.img);
	if (game->textures.exit.img)
		mlx_destroy_image(game->vars.mlx, game->textures.exit.img);
	if (game->textures.player_left.img)
		mlx_destroy_image(game->vars.mlx, game->textures.player_left.img);
	if (game->textures.player_right.img)
		mlx_destroy_image(game->vars.mlx, game->textures.player_right.img);
}

void	clear_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_map_array(game->map.map_array);
	free_textures(game);
	if (game->vars.window.window)
		mlx_destroy_window(game->vars.mlx, game->vars.window.window);
}