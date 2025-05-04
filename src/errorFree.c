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

#include "so_long.h"

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

void	ft_free_game_message(t_game *game, char *message)
{
	if (game)
		ft_free_struct_game(game);
	ft_error_message(message);
}
