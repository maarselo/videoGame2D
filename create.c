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

static int	ft_get_rows(char *file)
{
	int			fd;
	int			lines;
	char		*line;

	lines = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static int	ft_get_columns(char *file)
{
	int			fd;
	char		*line;
	int			columns;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	columns = ft_check_len(line);
	while (line)
	{
		if (columns != ft_check_len(line))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (columns);
}

static void	ft_fill_lines(char *file, t_map *map)
{
	int			fd;
	int			index;
	char		*line;

	index = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->map[index++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	ft_check_lines(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->rows)
	{
		if (!map->map[i])
		{
			ft_free_struct_map(map);
			ft_error();
		}
	}
}

t_map	*ft_create_map(char *file)
{
	int			total_lines;
	int			columns;
	t_map		*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error();
	total_lines = ft_get_rows(file);
	map->rows = total_lines;
	columns = ft_get_columns(file);
	map->columns = columns;
	map->map = malloc(sizeof(char *) * (total_lines + 1));
	if (!map->map)
	{
		free(map);
		ft_error();
	}
	map->map[total_lines] = NULL;
	ft_fill_lines(file, map);
	ft_check_lines(map);
	return (map);
}
