/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:51:32 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 14:51:33 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_file(int fd, char *file)
{
	if (!ft_strnstr(file, ".ber", ft_strlen(file)) || fd == -1)
		return (1);
	return (0);
}

static int	ft_read_file(int fd)
{
	int			first_len;
	char		*line ;

	line = get_next_line(fd);
	if (!line)
		return (1);
	first_len = ft_check_len(line);
	if (!first_len)
		return (1);
	while (line)
	{
		if (ft_check_line(line))
			return (1);
		free(line);
		line = get_next_line(fd);
		if (first_len != ft_check_len(line))
		{
			if (!ft_check_len(line))
				continue ;
			else
				return (1);
		}
	}
	close(fd);
	return (0);
}

static int	ft_create_fill_map(char *file, t_map *map)
{
	if (ft_create_map(file, map) || ft_fill_map(file, map->map))
		return (1);
	map->columns = ft_strlen(map->map[0]);
	return (0);
}

void	ft_check_entry_to_map(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (ft_check_file(fd, file) || ft_read_file(fd))
		ft_error();
	if (ft_create_fill_map(file, map))
		ft_putstr_fd("No se pudo asginar memory khay", 1);
}
