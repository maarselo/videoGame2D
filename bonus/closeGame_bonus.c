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

#include "so_long.h"

void	ft_check_exit(int new_x, int new_y, t_game *game)
{
	if (game->map->map[new_x][new_y] == 'E'
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

void	ft_close_x(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	ft_printf("\033[1;31mGame closed. See you next time! 👋\033[0m\n");
	ft_free_struct_game(g);
	exit(0);
}
