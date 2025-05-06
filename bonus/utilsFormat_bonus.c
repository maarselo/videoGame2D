/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsFormat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:30:32 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 14:30:33 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_line_quantity(char *line, char c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (line[i])
	{
		if (line[i] == c)
			total++;
		i++;
	}
	return (total);
}

int	ft_check_horizontal(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map->map[map->rows - 1][i])
	{
		if (map->map[map->rows - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_vertical(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1'
			|| map->map[i][ft_strlen(map->map[i]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
