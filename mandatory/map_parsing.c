/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:52:38 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/26 17:37:44 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *filename)
{
	char	ch;
	char	ret_val;
	int		count;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_code(ERR_OP_FILE, 11);
	count = 0;
	ret_val = 1;
	while (ret_val > 0)
	{
		ret_val = (int)read(fd, &ch, 1);
		if (ret_val == 0 || ch == '\n')
			count++;
	}
	close(fd);
	return (count);
}

static void	init_data(t_game *game)
{
	game->textures.collect.ptr = NULL;
	game->textures.exit.ptr = NULL;
	game->textures.p_l.ptr = NULL;
	game->textures.p_r.ptr = NULL;
	game->textures.empty.ptr = NULL;
	game->textures.wall.ptr = NULL;
	game->player.collected = 0;
	game->player.face_right = true;
	game->player.moves = 0;
}

static char	*get_line(int fd)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	temp = ft_strtrim(line, "\n");
	free(line);
	if (!temp)
		return (NULL);
	return (temp);
}

static char	**get_map_array(char *filename)
{
	char	**arr;
	int		lines;
	int		fd;
	int		i;

	lines = count_lines(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_code(ERR_OP_FILE, 6);
	arr = malloc(sizeof(char *) * (lines + 1));
	if (!arr)
		return (close(fd), NULL);
	i = 0;
	while (i < lines)
	{
		arr[i] = get_line(fd);
		if (!arr[i])
			break ;
		i++;
	}
	close(fd);
	arr[i] = NULL;
	return (arr);
}

void	map_parsing(t_game *game, char *filename)
{
	game->map.map_arr = get_map_array(filename);
	if (!game->map.map_arr)
		exit_code(ALLOC_FAIL, 9);
	init_data(game);
	map_parsing_2(game);
}
