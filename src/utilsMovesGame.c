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

#include "so_long.h"

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
				mlx_image_to_window(game->mlx, game->exit->open, j * PIXELS,
				i * PIXELS);
			j++;
		}
		i++;
	}
}

static void ft_check_exit(int new_x, int new_y, t_game *game)
{
	if (game->map->map[new_x][new_y] == 'E'
		&& game->map->collectionables == 0)
	{
		ft_printf("\033[1;32m🏆 ¡Felicidades!\nLa momia ya puede descansar en paz...\033[0m\n");
		ft_free_struct_game(game);
		exit(0);
	}
}

void ft_draw_moves(int new_x, int new_y, char *direction, t_game *game)
{
	if (game->map->map[new_x][new_y] == 'C')
		game->map->collectionables -= 1;
	mlx_image_to_window(game->mlx, game->floor, game->y * PIXELS,
		game->x * PIXELS);
	if (game->map->map[game->x][game->y] == 'E')
	{
		if (game->map->collectionables == 0)
			mlx_image_to_window(game->mlx, game->exit->open, game->y * PIXELS,
				game->x * PIXELS);
		else
			mlx_image_to_window(game->mlx, game->exit->close, game->y * PIXELS,
				game->x * PIXELS);
	}
	if (game->map->map[game->x][game->y] != 'E')
		game->map->map[game->x][game->y] = '0';
	if (game->map->map[new_x][new_y] != 'E')
		game->map->map[new_x][new_y] = 'P';
	game->x = new_x;
	game->y = new_y;
	if (!ft_strncmp(direction,"up", ft_strlen(direction)))
		mlx_image_to_window(game->mlx, game->character->up, game->y * PIXELS, game->x * PIXELS);
	else if (!ft_strncmp(direction,"left", ft_strlen(direction)))
		mlx_image_to_window(game->mlx, game->character->left, game->y * PIXELS, game->x * PIXELS);
	else if (!ft_strncmp(direction,"right", ft_strlen(direction)))
		mlx_image_to_window(game->mlx, game->character->right, game->y * PIXELS, game->x * PIXELS);
	else if (!ft_strncmp(direction,"down", ft_strlen(direction)))
		mlx_image_to_window(game->mlx, game->character->down, game->y * PIXELS, game->x * PIXELS);
	if (game->map->collectionables == 0)
		ft_open_exit(game);
	ft_check_exit(game->x, game->y, game);
}
