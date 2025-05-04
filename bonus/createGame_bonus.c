/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createGame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:44:12 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/01 16:44:13 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_set_coordinates(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->rows)
	{
		y = 0;
		while (y < game->map->columns)
		{
			if (game->map->map[x][y] == 'P')
			{
				game->x = x;
				game->y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

static mlx_t	*ft_init_window(t_game *game)
{
	mlx_t			*mlx;
	int				weight_to_pixels;
	int				height_to_pixels;

	weight_to_pixels = game->map->columns * PIXELS;
	height_to_pixels = game->map->rows * PIXELS;
	mlx = mlx_init(weight_to_pixels, height_to_pixels, "so_long", true);
	if (!mlx)
		ft_error_free_game(game);
	return (mlx);
}

static void	ft_init_images(t_game *game)
{
	game->wall = ft_load_image(WALL, "./Images/wall.png", game);
	game->floor = ft_load_image(FLOOR, "./Images/floor.png", game);
	game->collectionable = ft_load_image(COLLECTIONABLE, "./Images/Collectionable/diamond.png", game);
	game->character = ft_init_characters_images(game);
	game->exit = ft_init_exit_images(game);
	if (game->map->enemies > 0)
	{
		game->enemies = ft_init_enemies(game);
		ft_init_enemies_frame(game);
	}
}

t_game	*ft_create_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_error_free_map(map);
	game->map = map;
	ft_set_coordinates(game);
	game->moves = 0;
	game->mlx = ft_init_window(game);
	game->wall = NULL;
	game->floor = NULL;
	game->character = NULL;
	game->collectionable = NULL;
	game->exit = NULL;
	game->enemies = NULL;
	ft_init_images(game);
	return (game);
}
