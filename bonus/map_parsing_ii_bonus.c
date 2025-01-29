/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_ii_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:09:29 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/26 17:41:28 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static bool	validate_elements(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map.map_arr[++y])
	{
		x = -1;
		while (game->map.map_arr[y][++x])
		{
			if (game->map.map_arr[y][x] == 'C')
				game->map.nb_c += 1;
			else if (game->map.map_arr[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				game->map.nb_p += 1;
			}
			else if (game->map.map_arr[y][x] == 'E')
				game->map.nb_e += 1;
			else if (game->map.map_arr[y][x] != '0' && \
game->map.map_arr[y][x] != '1' && game->map.map_arr[y][x] != 'X')
				return (false);
		}
	}
	return (game->map.nb_c > 0 && game->map.nb_e == 1 && game->map.nb_p == 1);
}

static bool	is_map_rectangular(char **map)
{
	int	y;
	int	w;

	w = (int)ft_strlen(map[0]);
	y = 0;
	while (map[y])
	{
		if ((int)ft_strlen(map[y]) != w)
			return (false);
		y++;
	}
	return (true);
}

static bool	map_surrounded_by_walls(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map.map_arr[++y])
	{
		x = -1;
		while (game->map.map_arr[y][++x])
		{
			if (x == 0 || y == 0 || !game->map.map_arr[y + 1] || \
			!game->map.map_arr[y][x + 1])
			{
				if (game->map.map_arr[y][x] != '1')
					return (false);
			}
		}
	}
	game->map.height = y;
	game->map.width = x;
	return (true);
}

void	map_parsing_2(t_game *game)
{
	game->map.nb_c = 0;
	game->map.nb_e = 0;
	game->map.nb_p = 0;
	if (!validate_elements(game))
		clear_and_exit(game, NB_C_ERR "," NB_E_ERR "," NB_P_ERR, 14);
	if (!is_map_rectangular(game->map.map_arr))
		clear_and_exit(game, INV_MAP_DIM, 12);
	if (!map_surrounded_by_walls(game))
		clear_and_exit(game, MAP_SURR_WALL, 11);
	if (!valid_path(game))
		clear_and_exit(game, INV_PATH, 13);
	if (game->map.height > 25 || game->map.width > 50)
		clear_and_exit(game, INV_MAP_DIM, 12);
}
