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

static void	ft_key_hook(mlx_key_data_t key, void *game)
{
	t_game	*g;

	g = (t_game *)game;
	if ((key.key == MLX_KEY_W || key.key == MLX_KEY_A
			|| key.key == MLX_KEY_D || key.key == MLX_KEY_S)
		&& key.action == MLX_PRESS)
	{
		if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
			g->moves += ft_move_up(game);
		if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
			g->moves += ft_move_left(game);
		if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
			g->moves += ft_move_right(game);
		if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
			g->moves += ft_move_down(game);
		ft_printf("You moved %d times — The treasure awaits!\n", g->moves);
	}
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		ft_close(game);
}

static void	ft_close_x(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	ft_printf("\033[1;31mGame closed. See you next time! 👋\033[0m\n");
	ft_free_struct_game(g);
	exit(0);
}

void	ft_init_game(t_game *game)
{
	ft_first_draw(game);
	mlx_key_hook(game->mlx, ft_key_hook, game);
	mlx_close_hook(game->mlx, ft_close_x, game);
	mlx_loop(game->mlx);
}
