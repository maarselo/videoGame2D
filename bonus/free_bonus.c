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

#include "so_long_bonus.h"

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

void	ft_free_struct_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		ft_free_struct_map(game->map);
	if (game->moves_img)
		mlx_delete_image(game->mlx, game->moves_img);
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
	if (game->enemies)
		free(game->enemies);
	ft_delete_frames(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}
