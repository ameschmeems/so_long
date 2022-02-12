/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:00:37 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/07 20:57:49 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_map(char	*map, t_game *game)
{
	int			fd;
	int			size;
	static char	buffer[2048];

	fd = open(map, O_RDONLY);
	size = read(fd, buffer, 2048);
	if (size <= 0)
	{
		printf("Error\nFailed to read map file\n");
		exit(0);
	}
	buffer[size] = 0;
	game->map = buffer;
	close(fd);
}

void	check_newline(t_game *game, int *current_row, int *col_count, int i)
{
	if (game->map[i] == '\n')
	{
		game->screen_height += TILE_SIZE;
		if (*current_row != *col_count)
		{
			printf("Error\nMap isn't rectangular\n");
			exit(0);
		}
		*current_row = 0;
	}
	else
	{
		if (game->screen_height == 0)
			game->screen_width += TILE_SIZE;
		(*current_row)++;
	}
}

void	check_map(t_game *game)
{
	size_t	i;
	int		col_count;
	int		current_row;

	i = 0;
	col_count = 0;
	current_row = 0;
	game->screen_height = 0;
	game->screen_width = 0;
	while (game->map[col_count] && game->map[col_count] != '\n')
	{
		col_count++;
	}
	game->max_x = col_count + 1;
	while (game->map[i])
	{
		check_newline(game, &current_row, &col_count, i);
		i++;
	}
	if (current_row != col_count)
	{
		printf("Error\nMap isn't rectangular\n");
		exit(0);
	}
	game->screen_height += TILE_SIZE;
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (game->map[i])
	{
		if (check_tile(game, x, y, i))
		{
			x++;
			i++;
		}
		else
		{
			x = 0;
			y++;
			i++;
		}
	}
}
