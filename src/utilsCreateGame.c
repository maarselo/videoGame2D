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

t_character	*ft_init_characters_images(t_game *game)
{
	t_character		*c;

	c = (t_character *)malloc(sizeof(t_character));
	if (!c)
		ft_error_free_game(game);
	c->initial = ft_character("./Images/Character/initial.png", game, c);
	c->up = ft_character("./Images/Character/up.png", game, c);
	c->left = ft_character("./Images/Character/left.png", game, c);
	c->right = ft_character("./Images/Character/right.png", game, c);
	c->down = ft_character("./Images/Character/down.png", game, c);
	return (c);
}

t_exit	*ft_init_exit_images(t_game *game)
{
	t_exit			*exit;

	exit = (t_exit *)malloc(sizeof(t_exit));
	if (!exit)
		ft_error_free_game(game);
	exit->close = ft_exit("./Images/Exit/close.png", game, exit);
	exit->open = ft_exit("./Images/Exit/open.png", game, exit);
	return (exit);
}
