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

static mlx_t	*ft_init_window(t_game *game)
{
	mlx_t			*mlx;
	int			weight_to_pixels;
	int			height_to_pixels;

	weight_to_pixels = game->map->columns * PIXELS;
	height_to_pixels = game->map->rows * PIXELS;
	mlx = mlx_init(weight_to_pixels, height_to_pixels, "so_long", true);
	if (!mlx)
		ft_error_message_free_game(game);
	return (mlx);
}

static void	ft_init_images(t_game *game)
{
	mlx_texture_t	*texture;

	texture = ft_png_to_texture("./Images/wall1.png", game);
	game->wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = ft_png_to_texture("./Images/floor.png", game);
	game->floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	//texture = ft_png_to_texture(" ", game);
	//game->character = mlx_texture_to_image(game->mlx, texture);
	//ft_set_character_positions();
	//mlx_delete_texture(texture);
	//texture = ft_png_to_texture(" ", game);
	//game->collectionable = mlx_texture_to_image(game->mlx, texture);
	//ft_set_collectionable_positions();
	//mlx_delete_texture(texture);
	texture = ft_png_to_texture("./Images/Exit/exit_close.png", game);
	game->exit = mlx_texture_to_image(game->mlx, texture);
	//ft_set_exit_positions();
	mlx_delete_texture(texture);
}

t_game	*ft_create_game(t_map *map)
{
	t_game	*game;

	game = (t_game*)malloc(sizeof(t_game));
	if (!game)
		ft_error_message_free_map(map);
	game->map = map;
	game->mlx = ft_init_window(game);
	ft_init_images(game);
	if (!game->wall || !game->floor //|| !game->character || !game->collectionable
			|| !game->exit)
		ft_free_struct_game(game);
	return (game);
}
