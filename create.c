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

static int	ft_count_line(int fd)
{
	int			lines;
	char	*line;

	lines = 0;
	line = get_next_line(fd);
	while(line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	return (lines);
}

t_map	*ft_create_map(char *file)
{
	int			total_lines;
	t_map	*map;
	int			fd;

	fd = open(file, O_RDONLY);
	total_lines = ft_count_line(fd);
	map = (t_map *)malloc(sizeof(t_map));
	if (!total_lines || !map)
		return (NULL);
	map->rows = total_lines;
	map->columns = 0;
	map->map = (char **)malloc(sizeof(char *) * (total_lines + 1));
	if (!map->map)
	{
		free(map);
		return (NULL);
	}
	map->map[total_lines + 1] = NULL;
	close(fd);
	return (map);
}
