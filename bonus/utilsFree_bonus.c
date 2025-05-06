/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsFree_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:47:03 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/04 19:47:04 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_struct_character(t_game *game)
{
	if (!game->character)
		return ;
	if (game->character->initial)
		mlx_delete_image(game->mlx, game->character->initial);
	if (game->character->up)
		mlx_delete_image(game->mlx, game->character->up);
	if (game->character->left)
		mlx_delete_image(game->mlx, game->character->left);
	if (game->character->right)
		mlx_delete_image(game->mlx, game->character->right);
	if (game->character->down)
		mlx_delete_image(game->mlx, game->character->down);
	free(game->character);
	game->character = NULL;
}

void	ft_free_struct_exit(t_game *game)
{
	if (!game->exit)
		return ;
	if (game->exit->close)
		mlx_delete_image(game->mlx, game->exit->close);
	if (game->exit->open)
		mlx_delete_image(game->mlx, game->exit->open);
	free(game->exit);
	game->exit = NULL;
}

void	ft_delete_frames(t_game *game)
{
	int	i;

	if (!game || !game->mlx)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->enemy_frames[i])
		{
			mlx_delete_image(game->mlx, game->enemy_frames[i]);
			game->enemy_frames[i] = NULL;
		}
		i++;
	}
}
