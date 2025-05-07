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

#include "so_long_bonus.h"

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

static void	ft_check_exits_path(int x, int y, char **map, t_path *path)
{
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	else if (map[x][y] == 'C')
		++path->collectionables;
	else if (map[x][y] == 'E')
		++path->exit;
	map[x][y] = 'X';
	ft_check_exits_path(x - 1, y, map, path);
	ft_check_exits_path(x + 1, y, map, path);
	ft_check_exits_path(x, y - 1, map, path);
	ft_check_exits_path(x, y + 1, map, path);
}

void	ft_check_format(t_map *map, char *file)
{
	int			x;
	int			y;
	t_map		*copy_map;
	t_path		path;

	ft_check_letters_map(map);
	ft_check_borders(map);
	ft_check_is_rectangular(map);
	copy_map = ft_create_map(file);
	ft_init_values_path(&x, &y, &path, map);
	ft_check_exits_path(x, y, copy_map->map, &path);
	if (path.collectionables != map->collectionables || path.exit != 1)
	{
		ft_free_struct_map(copy_map);
		ft_error_message("\033[1;33mTrapped forever... no escape! 😵\033[0m\n");
	}
	ft_free_struct_map(copy_map);
}
