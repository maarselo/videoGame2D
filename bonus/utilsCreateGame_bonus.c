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

#include "so_long_bonus.h"

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

t_enemy	*ft_init_enemies(t_game *game)
{
	int				i;
	int				j;
	int				i_enemy;
	t_enemy			*enemies;

	i = 0;
	i_enemy = 0;
	enemies = malloc(sizeof(t_enemy) * game->map->enemies);
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->columns)
		{
			if (game->map->map[i][j] == 'A')
			{
				enemies[i_enemy].x = i;
				enemies[i_enemy].y = j;
				enemies[i_enemy].current_frame = 0;
				i_enemy++;
			}
			j++;
		}
		i++;
	}
	return (enemies);
}

void	ft_init_enemies_frame(t_game *game)
{
	game->enemy_frames[0] = ft_load_image(ENEMY, "./Images/Enemy/enemy1.png", game);
	game->enemy_frames[1] = ft_load_image(ENEMY, "./Images/Enemy/enemy2.png", game);
	game->enemy_frames[2] = ft_load_image(ENEMY, "./Images/Enemy/enemy3.png", game);
	game->enemy_frames[3] = ft_load_image(ENEMY, "./Images/Enemy/enemy4.png", game);
}