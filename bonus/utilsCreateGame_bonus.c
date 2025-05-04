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
	t_character		*character;
	mlx_texture_t	*texture_tmp;

	character = (t_character *)malloc(sizeof(t_character));
	if (!character)
		ft_error_free_game(game);
	texture_tmp = mlx_load_png("./Images/Character/initial.png");
	character->initial = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	texture_tmp = mlx_load_png("./Images/Character/up.png");
	character->up = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	texture_tmp = mlx_load_png("./Images/Character/left.png");
	character->left = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	texture_tmp = mlx_load_png("./Images/Character/right.png");
	character->right = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	texture_tmp = mlx_load_png("./Images/Character/down.png");
	character->down = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	if (!character->initial || !character->up || !character->left
		|| !character->right || !character->down)
		ft_error_character(character, game);
	return (character);
}

t_exit	*ft_init_exit_images(t_game *game)
{
	t_exit			*exit;
	mlx_texture_t	*texture_tmp;

	exit = (t_exit *)malloc(sizeof(t_exit));
	if (!exit)
		ft_error_free_game(game);
	texture_tmp = mlx_load_png("./Images/Exit/close.png");
	exit->close = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	texture_tmp = mlx_load_png("./Images/Exit/open1.png");
	exit->open = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	if (!exit->close || !exit->open)
		ft_error_exit(exit, game);
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
	mlx_texture_t	*texture_tmp;

	texture_tmp = mlx_load_png("./Images/Enemy/enemy1.png");
	game->enemy_frames[0] = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	texture_tmp = mlx_load_png("./Images/Enemy/enemy2.png");
	game->enemy_frames[1] = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	texture_tmp = mlx_load_png("./Images/Enemy/enemy3.png");
	game->enemy_frames[2] = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	texture_tmp = mlx_load_png("./Images/Enemy/enemy4.png");
	game->enemy_frames[3] = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);
	if (!game->enemy_frames[0] || !game->enemy_frames[1]
		|| !game->enemy_frames[2] || !game->enemy_frames[3])
		ft_error_enemies(game);
}