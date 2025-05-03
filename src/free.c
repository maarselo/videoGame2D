/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:29:41 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 16:29:43 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_struct_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	free(map);
}

static void	ft_free_struct_character(t_game *game)
{
    if (!game->character)
        return;
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

static void	ft_free_struct_exit(t_game *game)
{
    if (!game->exit)
        return;
    if (game->exit->close)
        mlx_delete_image(game->mlx, game->exit->close);
    if (game->exit->open)
        mlx_delete_image(game->mlx, game->exit->open);
    free(game->exit);
	game->exit = NULL;
}

void	ft_free_struct_game(t_game *game)
{
	if (!game)
		return;
	if (game->map)
		ft_free_struct_map(game->map);
	if (game->wall)
		mlx_delete_image(game->mlx, game->wall);
	if (game->floor)
		mlx_delete_image(game->mlx, game->floor);
	if (game->character)
		ft_free_struct_character(game);
	if (game->collectionable)
		mlx_delete_image(game->mlx, game->collectionable);
	if (game->exit)
		ft_free_struct_exit(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}


void	ft_free(t_game *game)
{
	ft_free_struct_game(game);
}
