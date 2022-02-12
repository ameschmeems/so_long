/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:49:32 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/02 06:28:58 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(int keycode, void *ptr)
{
	(void) ptr;
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	x_close(void *ptr)
{
	(void) ptr;
	exit(0);
	return (0);
}

void	horizontal_movement(int keycode, t_game	*game)
{
	if ((keycode == W_KEY || keycode == UP_KEY) \
		&& valid_move((game->char_x / 32), (game->char_y / 32) - 1, game))
	{
		game->char_y -= TILE_SIZE;
		mlx_put_image_to_window(game->mlx, game->win, game->char_backward,
			game->char_x, game->char_y);
		render_img(game, game->char_x, game->char_y + TILE_SIZE, game->lilypad);
		game->moves++;
		printf("Moves: %i\n", game->moves);
	}
	else if ((keycode == S_KEY || keycode == DOWN_KEY) \
		&& valid_move((game->char_x / 32), (game->char_y / 32) + 1, game))
	{
		game->char_y += TILE_SIZE;
		mlx_put_image_to_window(game->mlx, game->win, game->char_forward,
			game->char_x, game->char_y);
		render_img(game, game->char_x, game->char_y - TILE_SIZE, game->lilypad);
		game->moves++;
		printf("Moves: %i\n", game->moves);
	}
}

void	vertical_movement(int keycode, t_game *game)
{
	if ((keycode == A_KEY || keycode == LEFT_KEY) \
		&& valid_move((game->char_x / 32) - 1, (game->char_y / 32), game))
	{
		game->char_x -= TILE_SIZE;
		mlx_put_image_to_window(game->mlx, game->win, game->char_left,
			game->char_x, game->char_y);
		render_img(game, game->char_x + TILE_SIZE, game->char_y, game->lilypad);
		game->moves++;
		printf("Moves: %i\n", game->moves);
	}
	else if ((keycode == D_KEY || keycode == RIGHT_KEY) \
		&& valid_move((game->char_x / 32) + 1, (game->char_y / 32), game))
	{
		game->char_x += TILE_SIZE;
		mlx_put_image_to_window(game->mlx, game->win, game->char_right,
			game->char_x, game->char_y);
		render_img(game, game->char_x - TILE_SIZE, game->char_y, game->lilypad);
		game->moves++;
		printf("Moves: %i\n", game->moves);
	}
}

int	move(int keycode, t_game *game)
{
	horizontal_movement(keycode, game);
	vertical_movement(keycode, game);
	close_window(keycode, 0);
	return (0);
}
