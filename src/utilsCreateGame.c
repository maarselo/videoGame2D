/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsCreateGame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:17:10 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/01 18:17:12 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_texture_t	*ft_png_to_texture(char *path, t_game *game)
{
	mlx_texture_t	*to_image;

	to_image = mlx_load_png(path);
	if (!to_image)
	{
		ft_free_struct_game(game);
		ft_error_message("\033[1;33m🔍 Can't find PNG\033[0m\n");
	}
	return (to_image);
}


