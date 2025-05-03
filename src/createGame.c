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

#include "so_long.h"

static void	ft_set_coordinates(t_game *game)
{
	int	x;
	int y;

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
	mlx_texture_t	*texture;

	texture = mlx_load_png("./Images/wall.png");
	game->wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!game->wall)
		ft_free_game_message(game, "\033[1;33m🔍 Can't find wall PNG\033[0m\n");
	texture = mlx_load_png("./Images/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!game->floor)
		ft_free_game_message(game, "\033[1;33m🔍 Can't find floor PNG\033[0m\n");
	texture = mlx_load_png("./Images/Collectionable/diamond.png");
	game->collectionable = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!game->collectionable)
		ft_free_game_message(game, "\033[1;33m🔍 Can't find get PNG\033[0m\n");
	game->character = ft_init_characters_images(game);
	game->exit = ft_init_exit_images(game);
}

t_game	*ft_create_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_error_free_map(map);
	game->map = map;
	ft_set_coordinates(game);
	game->mlx = ft_init_window(game);
	game->wall = NULL;
	game->floor = NULL;
	game->character = NULL;
	game->collectionable = NULL;
	game->exit = NULL;
	ft_init_images(game);
	return (game);
}
