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

t_map	*ft_create_map()
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->rows = 0;
	map->columns = 0;
	map->map = NULL;
	return (map);
}