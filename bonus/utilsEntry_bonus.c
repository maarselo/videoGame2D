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
	char			*content_map;

	if (!line)
		return (1);
	i = 0;
	content_map = "01CEP";
	while (line[i])
	{
		if (line[i] != '\n' && !ft_strchr(content_map, line[i]))
			return (1);
		i++;
	}
	return (0);
}
