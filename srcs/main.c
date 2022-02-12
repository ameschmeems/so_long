/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:48:43 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/02 07:09:19 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.moves = 0;
	check_arguments(argc, argv);
	load_map(argv[1], &game);
	check_map(&game);
	check_map_reqs(&game);
	check_walls(&game);
	game.name = "So long! (and thanks for all the fish)";
	game.mlx = mlx_init();
	check_mlx_init(game.mlx);
	game.win = mlx_new_window(game.mlx, game.screen_width,
			game.screen_height, game.name);
	check_mlx_win(game.win);
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.win, move, &game);
	mlx_hook(game.win, ON_DESTROY, X_MASK, x_close, 0);
	mlx_loop(game.mlx);
}
