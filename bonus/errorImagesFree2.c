/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorImagesFree2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:24:15 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/04 20:24:16 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_enemies(t_game *game)
{
	if (game)
		ft_free_struct_game(game);
	ft_error_message("\033[1;33m🔍 Can't find enemies PNG\033[0m\n");
}
