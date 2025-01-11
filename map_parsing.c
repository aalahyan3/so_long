/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:07 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/05 15:02:32 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_extension(char *filename)
{
	char	**path;
	int		i;
	int		j;
	bool	ret;

	ret = false;
	j = 0;
	path = ft_split(filename, '/');
	if (!path)
		return (false);
	i = 0;
	while (path[i])
		i++;
	while (path[i - 1][j] && path[i - 1][j] != '.')
		j++;
	if (path[i - 1][j])
	{
		if (ft_strncmp(path[i - 1] + j, ".ber", 4) == 0)			
			ret = true;
		else
			ret = false;
	}
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	return (ret);
}

static int	get_nb_lines(char *filename)
{
	char	*line;
	int		fd;
	int		n;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0 || !line)
		exit_code(ERR_OP_FILE, 3);
	n = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		n++;
	}
	close(fd);
	return (n);
}

static char	**get_map(char *filename)
{
	char	**map;
	char	*temp;
	char 	*line;
	int		fd;
	int		i;

	map = malloc(sizeof(char *) * (get_nb_lines(filename) + 1));
	if (!map)
		exit_code(ALLOC_FAIL, 4);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0 || !line)
		exit_code(ERR_OP_FILE, 3);
	i = 0;
	while (line)
	{
		temp = ft_strtrim(line, "\n");
		map[i++] = temp;
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

t_map	parse_map(char *filename)
{
	char	**map_array;
	t_map	map;

	if (!check_extension(filename))
		exit_code(INVALID_EXT_MESSAGE, 2);
	map_array = get_map(filename);
	map.map_array = map_array;
	map.nb_player = 0;
	map.nb_collect = 0;
	map.nb_exits = 0;
	map_validation(&map);
	return (map);
}