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

static int	ft_move_up(t_game *game)
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

static int	ft_move_left(t_game *game)
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

static int	ft_move_right(t_game *game)
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

static int	ft_move_down(t_game *game)
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

void	ft_key_hook(mlx_key_data_t key, void *game)
{
	t_game	*g;

	g = (t_game *)game;
	if ((key.key == MLX_KEY_UP || key.key == MLX_KEY_LEFT
		|| key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_DOWN)
		&& key.action == MLX_PRESS)
	{
		if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
			g->moves += ft_move_up(game);
		if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
			g->moves += ft_move_left(game);
		if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
			g->moves += ft_move_right(game);
		if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
			g->moves += ft_move_down(game);
		ft_printf("You moved %d times — The treasure awaits!\n", g->moves);
	}
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		ft_close(game);
}
