/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:30:39 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/02 06:49:51 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_mlx_init(void	*mlx)
{
	if (!mlx)
	{
		printf("Error\nMlx failed to initialize\n");
		exit(0);
	}
}

void	check_mlx_win(void *win)
{
	if (!win)
	{
		printf("Error\nFailed to create window\n");
		exit(0);
	}
}

void	check_arguments(int argc, char **argv)
{
	size_t	i;

	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit(0);
	}
	i = ft_strlen(argv[1]) - 4;
	if (ft_strlen(argv[1]) < 4 || !ft_strnstr(&argv[1][i], ".ber", 4) ||
			ft_strlen(&argv[1][i]) != 4)
	{
		printf("Error\nWrong file type\n");
		exit(0);
	}
}

void	throw_error(char *message)
{
	printf("%s", message);
	exit(0);
}

void	check_map_reqs(t_game *game)
{
	size_t	i;

	i = 0;
	game->is_exit = 0;
	game->is_player = 0;
	game->to_collect = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'P')
			game->is_player++;
		else if (game->map[i] == 'E')
			game->is_exit++;
		else if (game->map[i] == 'C')
			game->to_collect++;
		i++;
	}
	if (game->is_player != 1)
		throw_error("Error\nNumber of player positions isn't equal to one\n");
	else if (!game->is_exit)
		throw_error("Error\nNo exit\n");
	else if (!game->to_collect)
		throw_error("Error\nNo Collectibles\n");
}
