/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveImage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:51:58 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/04 20:52:00 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_image_t	*ft_load_image(char *type, char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		if (!ft_strncmp(type, WALL, ft_strlen(type)))
			ft_error_wall(game);
		else if (!ft_strncmp(type, FLOOR, ft_strlen(type)))
			ft_error_floor(game);
		else if (!ft_strncmp(type, COLLECTIONABLE, ft_strlen(type)))
			ft_error_collectionable(game);
		else if (!ft_strncmp(type, ENEMY, ft_strlen(type)))
			ft_error_enemies(game);
	}
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

mlx_image_t	*ft_character(char *path, t_game *game, t_character *character)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error_character(character, game);
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

mlx_image_t	*ft_exit(char *path, t_game *game, t_exit *exit)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error_exit(exit, game);
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}
