/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:49:34 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/02 06:41:56 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_game *game)
{
	game->char_forward = mlx_xpm_file_to_image(game->mlx,
			"res/forg_forward.xpm", &game->width, &game->height);
	game->char_left = mlx_xpm_file_to_image(game->mlx, "res/forg_left.xpm",
			&game->width, &game->height);
	game->char_right = mlx_xpm_file_to_image(game->mlx, "res/forg_right.xpm",
			&game->width, &game->height);
	game->char_backward = mlx_xpm_file_to_image(game->mlx,
			"res/forg_backward.xpm",
			&game->width, &game->height);
	game->lilypad = mlx_xpm_file_to_image(game->mlx, "res/lilypad.xpm",
			&game->width, &game->height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "res/water.xpm",
			&game->width, &game->height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "res/collectible.xpm",
			&game->width, &game->height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "res/exit.xpm",
			&game->width, &game->height);
}

void	render_img(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

int	check_tile(t_game *game, int x, int y, int i)
{
	if (game->map[i] == '0')
		render_img(game, (x * TILE_SIZE), (y * TILE_SIZE), game->lilypad);
	else if (game->map[i] == 'E')
		render_img(game, (x * TILE_SIZE), (y * TILE_SIZE), game->exit);
	else if (game->map[i] == 'C')
		render_img(game, (x * TILE_SIZE), (y * TILE_SIZE), game->collectible);
	else if (game->map[i] == '1')
		render_img(game, (x * TILE_SIZE), (y * TILE_SIZE), game->wall);
	else if (game->map[i] == 'P')
	{
		render_img(game, (x * TILE_SIZE), (y * TILE_SIZE), game->char_forward);
		game->char_x = x * TILE_SIZE;
		game->char_y = y * TILE_SIZE;
	}
	else if (game->map[i] == '\n')
		return (0);
	else
	{
		printf("Error\nUnrecognized character in map %d\n", game->map[i]);
		exit(0);
	}
	return (1);
}
