/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesGame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:13:20 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/03 17:13:21 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_move_up(t_game *game)
{
	int	new_x;

	new_x = game->x - 1;
	if (ft_check_new_position(new_x, game->y, game))
	{
		ft_draw_moves(new_x, game->y, "up", game);
		return (1);
	}
	return (0);
}

int	ft_move_left(t_game *game)
{
	int	new_y;

	new_y = game->y - 1;
	if (ft_check_new_position(game->x, new_y, game))
	{
		ft_draw_moves(game->x, new_y, "left", game);
		return (1);
	}
	return (0);
}

int	ft_move_right(t_game *game)
{
	int	new_y;

	new_y = game->y + 1;
	if (ft_check_new_position(game->x, new_y, game))
	{
		ft_draw_moves(game->x, new_y, "right", game);
		return (1);
	}
	return (0);
}

int	ft_move_down(t_game *game)
{
	int	new_x;

	new_x = game->x + 1;
	if (ft_check_new_position(new_x, game->y, game))
	{
		ft_draw_moves(new_x, game->y, "down", game);
		return (1);
	}
	return (0);
}

void	ft_select_tile(int i, int j, t_game *game)
{
	if (game->map->map[i][j] == '1')
		mlx_image_to_window(game->mlx, game->wall,
			j * PX, i * PX);
	if (game->map->map[i][j] == 'P')
		mlx_image_to_window(game->mlx, game->character->initial,
			j * PX, i * PX);
	if (game->map->map[i][j] == 'E')
		mlx_image_to_window(game->mlx, game->exit->close,
			j * PX, i * PX);
	if (game->map->map[i][j] == 'C')
		mlx_image_to_window(game->mlx, game->collectionable,
			j * PX, i * PX);
	if (game->map->map[i][j] == 'A')
		mlx_image_to_window(game->mlx, game->enemy_frames[0],
			j * PX, i * PX);
}
