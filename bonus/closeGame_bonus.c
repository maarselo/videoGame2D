/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesGame2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:46:39 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/03 20:46:40 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_close_x(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	ft_printf("\033[1;31mGame closed. See you next time! 👋\033[0m\n");
	ft_free_struct_game(g);
	exit(0);
}

void	ft_check_enemy(t_game *game)
{
	if (game->map->map[game->x][game->y] == 'A')
	{
		ft_printf("\033[38;5;202m💥 Game Over! The monster ki...\033[0m\n");
		ft_free_struct_game(game);
		exit(0);
	}
}

void	ft_check_exit(t_game *game)
{
	if (game->map->map[game->x][game->y] == 'E'
		&& game->map->collectionables == 0)
	{
		ft_printf("\033[1;32m🏆 Victory! The mummy rests now.\033[0m\n");
		ft_free_struct_game(game);
		exit(0);
	}
}

void	ft_close(t_game *game)
{
	ft_printf("\033[1;33mYou chose the easy way, huh? 💤\033[0m\n");
	ft_free_struct_game(game);
	exit(0);
}
