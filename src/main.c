/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:30:32 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 14:30:33 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->columns)
		{
			mlx_image_to_window(game->mlx, game->floor, j * PIXELS, i * PIXELS);
			if (game->map->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, j * PIXELS, i * PIXELS);
			if (game->map->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->exit->close, j * PIXELS, i * PIXELS);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		return (1);
	ft_check_file(argv[1]);
	map = ft_create_map(argv[1]);
	ft_check_format(map);
	game = ft_create_game(map);
	ft_draw_map(game);
	mlx_loop(game->mlx);
	//ft_init_game()
	ft_free(game);
}
