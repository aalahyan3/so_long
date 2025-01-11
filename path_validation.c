/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:05:12 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/06 16:07:56 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int x, int y)
{
	if (y >= map->height || y < 0 || x >= map->width || x < 0)
		return ;
	if (map->map_array[y][x] == '1')
		return ;
	else if (map->map_array[y][x] == 'C')
		map->nb_collect -= 1;	
	else if (map->map_array[y][x] == 'E')
	{
		map->map_array[y][x] = '1';
		map->nb_exits += 1;
		return ;
	}
	map->map_array[y][x] = '1';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

bool	valid_path(t_map *map)
{
	t_map	map_clone;
	int		i;

	map_clone.map_array = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map_array)
		return (false);
	i = 0;
	while (map->map_array[i])
	{
		map_clone.map_array[i] = ft_strdup(map->map_array[i]);
		if (!map_clone.map_array[i])
		{
			free_map_array(map_clone.map_array);
			return (false);
		}
		i++;
	}
	map_clone.map_array[i] = NULL;
	map_clone.nb_collect = map->nb_collect;
	map_clone.nb_exits = 0;
	map_clone.height = map->height;
	map_clone.width = map->width;
	flood_fill(&map_clone, map->player_x, map->player_y);
	free_map_array(map_clone.map_array);
	return (map_clone.nb_collect == 0 && map_clone.nb_exits == 1);
}
