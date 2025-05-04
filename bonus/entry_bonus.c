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

#include "so_long_bonus.h"

static int	ft_check_file_is_correct(int fd, char *file)
{
	int	len;

	if (fd == -1)
		return (1);
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4))
		return (1);
	return (0);
}

static int	ft_read_file(int fd)
{
	int			first_len;
	int			to_return;
	char		*line ;

	to_return = 0;
	line = get_next_line(fd);
	if (!line)
		return (1);
	first_len = ft_check_len(line);
	if (!first_len)
		to_return = 1;
	while (line)
	{
		if (ft_check_line(line) || ft_check_len(line) != first_len)
			to_return = 1;
		free(line);
		line = get_next_line(fd);
	}
	return (to_return);
}

void	ft_check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (ft_check_file_is_correct(fd, file) || ft_read_file(fd))
	{
		if (fd != -1)
		{
			close(fd);
			ft_error_message("⚠️ \033[1;33m Invalid map content.\033[0m\n");
		}
		ft_error_message("⚠️ \033[1;33m Invalid file.\033[0m\n");
	}
	close(fd);
}
