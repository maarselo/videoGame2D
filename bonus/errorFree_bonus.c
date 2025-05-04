/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorFree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 01:14:16 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/03 01:14:17 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_free_map(t_map *map)
{
	if (map)
		ft_free_struct_map(map);
	ft_error();
}

void	ft_error_free_game(t_game *game)
{
	if (game)
		ft_free_struct_game(game);
	ft_error();
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

//for error with the game need meessage
void	ft_free_game_message(t_game *game, char *message)
{
	if (game)
		ft_free_struct_game(game);
	ft_error_message(message);
}
