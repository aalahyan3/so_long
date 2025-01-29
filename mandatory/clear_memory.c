/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:14:55 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/26 16:38:35 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	clear_all(game);
	if (game->vars.window && game->vars.mlx)
		mlx_destroy_window(game->vars.mlx, game->vars.window);
	exit (0);
	return (0);
}

void	clear_all(t_game *game)
{
	free_map_array(game->map.map_arr);
	if (game->textures.collect.ptr)
		mlx_destroy_image(game->vars.mlx, game->textures.collect.ptr);
	if (game->textures.empty.ptr)
		mlx_destroy_image(game->vars.mlx, game->textures.empty.ptr);
	if (game->textures.wall.ptr)
		mlx_destroy_image(game->vars.mlx, game->textures.wall.ptr);
	if (game->textures.exit.ptr)
		mlx_destroy_image(game->vars.mlx, game->textures.exit.ptr);
	if (game->textures.p_l.ptr)
		mlx_destroy_image(game->vars.mlx, game->textures.p_l.ptr);
	if (game->textures.p_r.ptr)
		mlx_destroy_image(game->vars.mlx, game->textures.p_r.ptr);
}

void	clear_and_exit(t_game *game, char *message, int code)
{
	clear_all(game);
	exit_code(message, code);
}
