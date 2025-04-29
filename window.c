/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:15:57 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/29 18:15:59 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_t	*ft_init_window(t_map *map)
{
	mlx_t	*mlx;
	int			weight_to_pixels;
	int			height_to_pixels;

	weight_to_pixels = map->columns * PIXELS_W;
	height_to_pixels = map->rows * PIXELS_H;
	mlx = mlx_init(weight_to_pixels, height_to_pixels, "so_long", false);

	return (mlx);
}