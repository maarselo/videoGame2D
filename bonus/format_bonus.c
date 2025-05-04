/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:56:01 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/21 16:56:02 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_letters_map(t_map *map)
{
	int		index;
	int		start;
	int		exit;

	index = 0;
	start = 0;
	exit = 0;
	while (index < map->rows)
	{
		start += ft_check_line_quantity(map->map[index], 'P');
		exit += ft_check_line_quantity(map->map[index], 'E');
		map->collectionables += ft_check_line_quantity(map->map[index], 'C');
		index++;
	}
	if (start != 1 || exit != 1 || map->collectionables < 1)
	{
		ft_free_struct_map(map);
		ft_error_message("⚠️ \033[1;33m Invalid map content.\033[0m\n");
	}
}

static void	ft_check_borders(t_map *map)
{
	if (ft_check_horizontal(map) || ft_check_vertical(map))
	{
		ft_free_struct_map(map);
		ft_error_message("\033[1;33m🚧 Map not closed with '1'.\033[0m\n");
	}
}

static void	ft_check_is_rectangular(t_map *map)
{
	if (map->columns <= map->rows)
	{
		ft_free_struct_map(map);
		ft_error_message("\033[1;33m🚧 Map must be rectangular.\033[0m\n");
	}
}
/*
static void	ft_check_exits_path(t_map *map)
{

}
*/

void	ft_check_format(t_map *map)
{
	ft_check_letters_map(map);
	ft_check_borders(map);
	ft_check_is_rectangular(map);
}
