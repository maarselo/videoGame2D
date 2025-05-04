/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorFreeImages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:16:06 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/04 20:16:08 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_wall(t_game *game)
{
	if (game)
		ft_free_struct_game(game);
	ft_error_message("\033[1;33m🔍 Can't find wall PNG\033[0m\n");
}

void	ft_error_floor(t_game *game)
{
	if (game)
		ft_free_struct_game(game);
	ft_error_message("\033[1;33m🔍 Can't find floor PNG\033[0m\n");
}

void	ft_error_collectionable(t_game *game)
{
	if (game)
		ft_free_struct_game(game);
	ft_error_message("\033[1;33m🔍 Can't find collectionable PNG\033[0m\n");
}

void	ft_error_character(t_character *character, t_game *game)
{
	if (!character)
		return ;
	if (character->initial)
		mlx_delete_image(game->mlx, character->initial);
	if (character->up)
		mlx_delete_image(game->mlx, character->up);
	if (character->left)
		mlx_delete_image(game->mlx, character->left);
	if (character->right)
		mlx_delete_image(game->mlx, character->right);
	if (character->down)
		mlx_delete_image(game->mlx, character->down);
	if (game)
		ft_free_struct_game(game);
	free(character);
	character = NULL;
	ft_error_message("\033[1;33m🔍 Can't find characters PNG\033[0m\n");
}

void	ft_error_exit(t_exit *exit, t_game *game)
{
	if (!exit)
		return ;
	if (exit->close)
		mlx_delete_image(game->mlx, exit->close);
	if (exit->open)
		mlx_delete_image(game->mlx, exit->open);
	if (game)
		ft_free_struct_game(game);
	free(exit);
	exit = NULL;
	ft_error_message("\033[1;33m🔍 Can't find exits PNG\033[0m\n");
}
