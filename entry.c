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

static void	ft_check_line(char *line)
{
	char	*content_map;

	content_map = "01CEP";
	while (*line)
	{
		if (*line != '\n' && !ft_strchr(content_map, *line))
		{
			free(line);
			return (1);
		}
		line++;
	}
	return (0);
}

static int	ft_read_file(int fd, t_map *map)
{
	int			rows;
	int			columns;
	int			first_len;
	char		*line ;

	rows = 0;
	columns = 0;
	first_len = ft_check_len(line);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_check_line(line))
		{
			free(line);
			return (1);
		}
		ft_to_map(rows, line, )
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
	return (0);
}

void	ft_check_entry_to_map(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (ft_check_file(fd, file))
		ft_error();
	
	ft_read_file(fd, map);
	if (!map)

	return (0);
}
