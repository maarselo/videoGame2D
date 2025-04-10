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

static int	ft_check_line(char *line)
{
	char	*content_map;

	content_map = "01CEP";
	while (*line)
	{
		if (*line != '\n' && !ft_strchr(content_map, *line))
			return (1);
		line++;
	}
	return (0);
}

static int	ft_read_file(int fd)
{
	int		len;
	char	*line ;

	line = get_next_line(fd);
	len = ft_check_len(line);
	while (line)
	{
		if (ft_check_line(line))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
		if (len != ft_check_len(line))
		{
			if (!ft_check_len(line))
				continue ;
			else
				return (1);
		}
	}
	return (0);
}

int	ft_check_entry(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!ft_strnstr(file, ".ber", ft_strlen(file)) || fd == -1)
		ft_error();
	if (ft_read_file(fd))
		ft_error();
	return (fd);
}
