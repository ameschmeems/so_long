/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:28:30 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/02 06:41:58 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_collectibles(t_game *game, int index)
{
	if (game->map[index] == 'C')
	{
		game->to_collect--;
		game->map[index] = '0';
	}
}

int	check_exit(t_game *game, int index)
{
	if (game->map[index] == 'E' && !game->to_collect)
	{
		printf("Congratulations for completing the level!\n");
		exit(0);
	}
	else if (game->map[index] == 'E')
		return (1);
	return (0);
}

int	valid_move(int new_x, int new_y, t_game *game)
{	
	if (!(game->map[new_x + (new_y * game->max_x)] == '1'))
	{
		check_collectibles(game, new_x + (new_y * game->max_x));
		if (check_exit(game, new_x + (new_y * game->max_x)))
			return (0);
		return (1);
	}
	else
	{
		return (0);
	}
}
