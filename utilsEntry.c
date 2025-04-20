/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsEntry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:35:54 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 18:35:55 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_check_line(char *line)
{
	int				i;
	char	*content_map;

	i = 0;
	content_map = "01CEP";
	while (line[i])
	{
		if (line[i] != '\n' && !ft_strchr(content_map, line[i]))
		{
			free(line);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_count_line(char *file)
{
	int			fd;
	int			lines;
	char	*line;

	lines = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

int	ft_fill_map(char *file, char **map)
{
	int			fd;
	int			i;
	int			len;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[i] = ft_strdup(line);
		if (!map[i])
			return (1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}