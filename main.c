/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:18:22 by aalahyan          #+#    #+#             */
/*   Updated: 2025/01/07 20:43:38 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_code(char *message, int code)
{
	ft_putendl_fd(message, 2);
	exit(code);
}

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_game	game;

	//atexit(leaks);
	if (ac != 2)
		exit_code(INVALID_ARGS_MESSAGE, 1);
	game.map = parse_map(av[1]);
	game.vars.mlx = mlx_init();
	if (!game.vars.mlx)
		exit_code(ERR_MLX_INIT, 8);
	render_game(&game);
	render_frame(&game);
	mlx_loop(game.vars.mlx);
	ft_printf("%s", av[0]);
	free_map_array(game.map.map_array);
}
