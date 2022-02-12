/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 04:24:23 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/02 07:08:59 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define X_MASK 0L
# define TILE_SIZE 32

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	*name;
	char	*map;
	void	*char_forward;
	void	*char_left;
	void	*char_right;
	void	*char_backward;
	void	*wall;
	void	*lilypad;
	void	*collectible;
	void	*exit;
	int		width;
	int		height;
	int		char_x;
	int		char_y;
	int		max_x;
	int		screen_width;
	int		screen_height;
	int		moves;
	int		to_collect;
	int		is_player;
	int		is_exit;
}	t_game;

enum e_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_key {
	ESC = 65307,
	UP_KEY = 65362,
	DOWN_KEY = 65364,
	LEFT_KEY = 65361,
	RIGHT_KEY = 65363,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100,
	W_KEY = 119
};

// error handling
void	check_mlx_init(void	*mlx);
void	check_mlx_win(void *win);
void	check_arguments(int argc, char **argv);
void	throw_error(char *message);

// key handling
int		move(int keycode, t_game *game);
int		x_close(void *ptr);

// image loading and rendering
void	load_images(t_game *game);
void	render_img(t_game *game, int x, int y, void *img);

// map handling
void	load_map(char	*map, t_game *game);
void	check_map(t_game *game);
void	check_map_reqs(t_game *game);
void	check_walls(t_game *game);
int		check_tile(t_game *game, int x, int y, int i);
void	render_map(t_game *game);

// collisions
int		valid_move(int new_x, int new_y, t_game *game);

#endif
