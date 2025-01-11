/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:29:25 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/06 17:25:29 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	valid_dimentions(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = (int)ft_strlen(map->map_array[y]);
	while (map->map_array[y])
	{
		if (x != (int)ft_strlen(map->map_array[y]) && map->map_array[y + 1])
			return (false);
		y++;
	}
	if (x > 100 || y > 50 || x <= y)
		return (false);
	map->height = y;
	map->width = x;
	return (true);
}

static bool	components_validation(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map_array[j])
	{
		i = 0;
		while (map->map_array[j][i])
		{
			if (map->map_array[j][i] == 'P')
			{
				map->nb_player += 1;
				map->player_x = i;
				map->player_y = j;
			}
			else if (map->map_array[j][i] == 'E')
				map->nb_exits += 1;
			else if (map->map_array[j][i] == 'C')
				map->nb_collect += 1;
			else
			{
				if (map->map_array[j][i] != '0' && map->map_array[j][i] != '1')
					return (false);
			}
			i++;
		}
		j++;
	}
	if (map->nb_player != 1 || map->nb_exits != 1 || map->nb_collect < 1)
		return (false);
	return (true);
}

static bool	surrounded_by_walls(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map_array[j])
	{
		i = 0;
		while (map->map_array[j][i])
		{
			if (i == 0 || i == map->width - 1 || j == 0 || j == map->height - 1)
			{
				if (map->map_array[j][i] != '1')
					return (false);
			}
			i++;
		}
		j++;
	}
	return (true);
}

void	map_validation(t_map *map)
{
	if (!valid_dimentions(map))
	{
		free_map_array(map->map_array);
		exit_code(INV_DIMENTIONS, 5);
	}
	if (!components_validation(map))
	{
		free_map_array(map->map_array);
		exit_code(INV_COMPONENTS, 6);
	}
	if (!surrounded_by_walls(map))
	{
		free_map_array(map->map_array);
		exit_code(MAP_NOT_SURR_BY_WALLS, 7);
	}
	if (!valid_path(map))
	{
		free_map_array(map->map_array);
		exit_code(MAP_PATH_ERR, 8);
	}
}