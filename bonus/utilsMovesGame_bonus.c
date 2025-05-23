/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsMovesGame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:46:12 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/03 17:46:15 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_new_position(int x, int y, t_game *game)
{
	return (game->map->map[x][y] != '1');
}

static void	ft_open_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->columns)
		{
			if (game->map->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->exit->open,
					j * PX, i * PX);
			j++;
		}
		i++;
	}
}

static void	ft_draw_character(char *direction, t_game *game)
{
	if (!ft_strncmp(direction, "up", 2))
		mlx_image_to_window(game->mlx, game->character->up, game->y * PX,
			game->x * PX);
	else if (!ft_strncmp(direction, "left", 4))
		mlx_image_to_window(game->mlx, game->character->left, game->y * PX,
			game->x * PX);
	else if (!ft_strncmp(direction, "right", 5))
		mlx_image_to_window(game->mlx, game->character->right, game->y * PX,
			game->x * PX);
	else if (!ft_strncmp(direction, "down", 4))
		mlx_image_to_window(game->mlx, game->character->down, game->y * PX,
			game->x * PX);
}

void	ft_draw_moves(int new_x, int new_y, char *direction, t_game *game)
{
	if (game->map->map[new_x][new_y] == 'C')
		game->map->collectionables -= 1;
	mlx_image_to_window(game->mlx, game->floor, game->y * PX,
		game->x * PX);
	if (game->map->map[game->x][game->y] == 'E')
		mlx_image_to_window(game->mlx, game->exit->close, game->y * PX,
			game->x * PX);
	if (game->map->map[game->x][game->y] != 'E')
		game->map->map[game->x][game->y] = '0';
	if (game->map->map[new_x][new_y] != 'E'
		&& game->map->map[new_x][new_y] != 'A')
		game->map->map[new_x][new_y] = 'P';
	game->x = new_x;
	game->y = new_y;
	ft_draw_character(direction, game);
	if (game->map->collectionables == 0)
		ft_open_exit(game);
	ft_check_enemy(game);
	ft_check_exit(game);
}
