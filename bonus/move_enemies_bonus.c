/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:24:46 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/22 18:57:20 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_enemy(t_game *game, int x, int y)
{
	int	dx;
	int	dy;

	dx = rand() % 3 - 1;
	dy = rand() % 3 - 1;
	if (dx && dy)
		dx = 0;
	if (game->map.map_arr[y + dy][x + dx] == '1' || \
	game->map.map_arr[y + dy][x + dx] == 'E' || \
	game->map.map_arr[y + dy][x + dx] == 'C' || \
	game->map.map_arr[y + dy][x + dx] == 'X' || \
	game->map.map_arr[y + dy][x + dx] == 'x')
		return ;
	if (game->map.map_arr[y + dy][x + dx] == 'P')
		game_over(game, false);
	game->map.map_arr[y][x] = '0';
	game->map.map_arr[y + dy][x + dx] = 'x';
}

void	move_enemies(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (game->map.map_arr[++y])
	{
		x = -1;
		while (game->map.map_arr[y][++x])
		{
			if (game->map.map_arr[y][x] == 'X')
				move_enemy(game, x, y);
		}
	}
	y = -1;
	while (game->map.map_arr[++y])
	{
		x = -1;
		while (game->map.map_arr[y][++x])
		{
			if (game->map.map_arr[y][x] == 'x')
				game->map.map_arr[y][x] = 'X';
		}
	}
}
