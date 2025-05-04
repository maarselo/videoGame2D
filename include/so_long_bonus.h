/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:45:55 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 14:45:56 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../Libs/Libft/libft.h"
# include "../Libs/MLX42/include/MLX42/MLX42.h"

# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

# define PIXELS 32

# define WALL "wall"
# define FLOOR "floor"
# define COLLECTIONABLE "collectionable"
# define CHARACTER "character"
# define EXIT "exit"
# define ENEMY "enemy"

typedef struct s_map
{
	int			rows;
	int			columns;
	int			collectionables;
	int			enemies;
	char		**map;
}				t_map;	

typedef struct s_character
{
	mlx_image_t	*initial;
	mlx_image_t	*up;
	mlx_image_t	*left;
	mlx_image_t	*right;
	mlx_image_t	*down;
}			t_character;

typedef struct s_exit
{
	mlx_image_t	*close;
	mlx_image_t	*open;
}			t_exit;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			current_frame;
}			t_enemy;

typedef struct s_game
{
	int			x;
	int			y;
	int			moves;
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	t_character	*character;
	mlx_image_t	*collectionable;
	t_exit		*exit;
	t_enemy		*enemies;
	mlx_image_t *enemy_frames[4];
}			t_game;

int			ft_check_len(char *str);
int			ft_check_line(char *line);
void		ft_check_file(char *file);
void		ft_count_enemies(t_map *map);

t_map		*ft_create_map(char *file);

int			ft_check_line_quantity(char *line, char c);
int			ft_check_horizontal(t_map *map);
int			ft_check_vertical(t_map *map);
void		ft_check_format(t_map *map);

mlx_image_t	*ft_exit(char *path, t_game *game, t_exit *exit);
mlx_image_t	*ft_character(char *path, t_game *game, t_character *character);
mlx_image_t	*ft_load_image(char *type, char *path, t_game *game);
t_character	*ft_init_characters_images(t_game *game);
t_exit		*ft_init_exit_images(t_game *game);
t_enemy		*ft_init_enemies(t_game *game);
void		ft_init_enemies_frame(t_game *game);
t_game		*ft_create_game(t_map *map);

void		ft_select_tile(int i, int j, t_game *game);
int			ft_move_up(t_game *game);
int			ft_move_left(t_game *game);
int			ft_move_right(t_game *game);
int			ft_move_down(t_game *game);
int			ft_check_new_position(int x, int y, t_game *game);
void		ft_draw_moves(int new_x, int new_y, char *direction, t_game *game);

void		ft_check_exit(int new_x, int new_y, t_game *game);
void		ft_close(t_game *game);

void		ft_init_game(t_game *game);

void		ft_error(void);
void		ft_error_message(char *message);

void		ft_error_free_map(t_map *map);
void		ft_error_free_game(t_game *game);

void		ft_error_wall(t_game *game);
void		ft_error_floor(t_game *game);
void		ft_error_collectionable(t_game *game);
void		ft_error_character(t_character *character, t_game *game);
void		ft_error_exit(t_exit *exit, t_game *game);
void		ft_error_enemies(t_game *game);

void		ft_free_game_message(t_game *game, char *message);


void		ft_free_struct_character(t_game *game);
void		ft_free_struct_exit(t_game *game);
void		ft_delete_frames(t_game *game);
void		ft_free_struct_map(t_map *map);
void		ft_free_struct_game(t_game *game);
#endif
