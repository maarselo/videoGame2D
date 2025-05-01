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
			i++;
		}
		free(map->map);
	}
	free(map);
}

void	ft_free_struct_game(t_game *game)
{
	if (!game)
		return;
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		ft_free_struct_map(game->map);
	if (game->wall)
		mlx_delete_image(game->mlx, game->wall);
	if (game->floor)
		mlx_delete_image(game->mlx, game->floor);
	if (game->character)
		mlx_delete_image(game->mlx, game->character);
	if (game->collectionable)
		mlx_delete_image(game->mlx, game->collectionable);
	if (game->exit)
		mlx_delete_image(game->mlx, game->exit);
	free(game);
}


void	ft_free(t_map *map)
{
	ft_free_struct_game(map);
}
