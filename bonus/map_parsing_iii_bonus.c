/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_iii_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:53:18 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/22 17:49:34 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	flood_fill(t_map *map, int x, int y)
{
	if (y >= map->height || y < 0 || x >= map->width || x < 0)
		return ;
	if (map->map_arr[y][x] == '1')
		return ;
	else if (map->map_arr[y][x] == 'C')
		map->nb_c -= 1;
	else if (map->map_arr[y][x] == 'E')
	{
		map->map_arr[y][x] = '1';
		map->nb_e += 1;
		return ;
	}
	map->map_arr[y][x] = '1';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

bool	valid_path(t_game *game)
{
	t_map	clone;
	int		i;

	clone.map_arr = malloc(sizeof(char *) * (game->map.height + 1));
	if (!clone.map_arr)
		return (false);
	i = -1;
	while (game->map.map_arr[++i])
	{
		clone.map_arr[i] = ft_strdup(game->map.map_arr[i]);
		if (!clone.map_arr[i])
		{
			clone.map_arr[i] = NULL;
			free_map_array(clone.map_arr);
			return (false);
		}
	}
	clone.map_arr[i] = NULL;
	clone.nb_c = game->map.nb_c;
	clone.nb_e = 0;
	clone.height = game->map.height;
	clone.width = game->map.width;
	flood_fill(&clone, game->player.x, game->player.y);
	free_map_array(clone.map_arr);
	return (clone.nb_c == 0 && clone.nb_e == 1);
}
