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

#include "so_long.h"

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
