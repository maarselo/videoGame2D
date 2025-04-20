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

static int	ft_count_line(char *file)
{
	int			fd = open(file, O_RDONLY);
	printf("%s", get_next_line(fd));
	/*
	int			lines;
	char	*line;

	lines = 0;
	while((line = get_next_line(fd)))
	{
		lines++;
		//free(line);
	}
	return (lines);*/
	return (0);
}

t_map	*ft_create_map(char *file)
{
	int			total_lines;
	t_map		*map = NULL;

	total_lines = ft_count_line(file);
	printf("you:%dnigg", total_lines);
	//map = (t_map *)malloc(sizeof(t_map));
	/*if (!map)
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
	close(fd);*/
	return (map);
}
