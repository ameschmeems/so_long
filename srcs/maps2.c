/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 07:10:32 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/02 07:57:31 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_last_line(t_game *game, int last_index)
{
	while (game->map[last_index] != '\n')
	{
		if (game->map[last_index] != '1')
			throw_error("Error\nMap isn't surrounded by walls\n");
		last_index--;
	}
}

void	check_walls(t_game *game)
{
	size_t	i;
	int		last_index;

	i = 0;
	last_index = ft_strlen(&game->map[i]) - 1;
	while (game->map[i])
	{
		if (game->map[i] == '\n')
			break ;
		else if (game->map[i] != '1')
			throw_error("Error\nMap isn't surrounded by walls\n");
		i++;
	}
	while (game->map[i])
	{
		if (game->map[i] == '\n' && \
			!(game->map[i - 1] == '1' && game->map[i + 1] == '1'))
			throw_error("Error\nMap isn't surrounded by walls\n");
		i++;
	}
	check_last_line(game, last_index);
}
