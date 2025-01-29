/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:55:51 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/24 17:57:56 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_code(char *message, int code)
{
	if (message)
	{
		ft_putstr_fd(RED "Error :", 2);
		ft_putendl_fd(message, 2);
		ft_putstr_fd(RESET, 2);
	}
	exit(code);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		exit_code(INV_ARGS_ERR, 1);
	file_validation(av[1]);
	map_parsing(&game, av[1]);
	game.vars.mlx = mlx_init();
	game.vars.window = NULL;
	if (!game.vars.mlx)
		exit_code(MLX_INIT_FAIL, 5);
	load_data(&game);
	start_game(&game);
}
