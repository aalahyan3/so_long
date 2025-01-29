/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:01:50 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/26 16:14:27 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ext_validation(char *filename)
{
	char	*base;
	char	*ext;

	base = ft_strrchr(filename, '/');
	if (!base)
		base = filename;
	else
		base++;
	ext = ft_strrchr(base, '.');
	if (ext && ft_strncmp(ext, ".ber", 4) == 0 && *(ext + 4) == '\0')
		return (true);
	return (false);
}

void	file_validation(char *filename)
{
	int	fd;

	if (!ext_validation(filename))
		exit_code(INV_EXT, 4);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, &fd, 0) < 0)
		exit_code(ERR_OP_FILE, 3);
	close(fd);
}
