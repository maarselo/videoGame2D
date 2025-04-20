/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:19:27 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 16:19:28 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_create_map(char *file, t_map *map)
{
	int	total_lines;

	total_lines = ft_count_line(file);
	map.rows = total_lines;
	map.columns = -1;
	map.map = (char **)malloc(sizeof(char *) * total_lines);
	if (!map.map)
		return (1);
	return (0);
}