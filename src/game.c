/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:06:30 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/03 16:06:31 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_first_draw(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->rows)
	{
		j = -1;
		while (++j < game->map->columns)
		{
			mlx_image_to_window(game->mlx, game->floor, j * PIXELS, i * PIXELS);
			if (game->map->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, 
					j * PIXELS, i * PIXELS);
			if (game->map->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->character->initial, 
					j * PIXELS, i * PIXELS);
			if (game->map->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->exit->close, 
					j * PIXELS, i * PIXELS);
			if (game->map->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->collectionable, 
					j * PIXELS, i * PIXELS);
		}
	}
}

void	ft_init_game(t_game *game)
{
	ft_first_draw(game);
	mlx_key_hook(game->mlx, ft_key_hook, game);
	mlx_close_hook(game->mlx, ft_close_x, game);
	mlx_loop(game->mlx);
}