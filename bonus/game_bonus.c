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

#include "so_long_bonus.h"

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
			mlx_image_to_window(game->mlx, game->floor, j * PX, i * PX);
			ft_select_tile (i, j, game);
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

static void	ft_animate_enemies(void *game)
{
	int			i;
	static int	timer;
	t_game		*g;
	t_enemy		*enemy_tmp;

	g = (t_game *)game;
	timer++;
	if (timer > 15)
	{
		i = -1;
		timer = 0;
		while (++i < g->map->enemies)
		{
			enemy_tmp = &g->enemies[i];
			if (g->floor)
				mlx_image_to_window(g->mlx, g->floor, enemy_tmp->y * PX,
					enemy_tmp->x * PX);
			mlx_image_to_window(g->mlx,
				g->enemy_frames[enemy_tmp->current_frame],
				enemy_tmp->y * PX, enemy_tmp->x * PX);
			enemy_tmp->current_frame++;
			if (enemy_tmp->current_frame >= 4)
				enemy_tmp->current_frame = 0;
		}
	}
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
	mlx_loop_hook(game->mlx, &ft_animate_enemies, game);
	mlx_close_hook(game->mlx, ft_close_x, game);
	mlx_loop(game->mlx);
}
