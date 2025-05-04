/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:45:55 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 14:45:56 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//incluye malloc, unistd, stdfdeff for size, limits.h
# include "../Libs/Libft/libft.h"
# include "../Libs/MLX42/include/MLX42/MLX42.h"

# include <stdlib.h> //malloc
# include <fcntl.h> //for open file
# include <limits.h> //int max
# include <unistd.h> //write
# include <stdio.h> //for test

# define PIXELS 32

typedef struct s_map
{
	int			rows;
	int			columns;
	int			collectionables;
	char		**map;
}				t_map;	

//This is for animations
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
///////////////////

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
}			t_game;

//entry and utils
int			ft_check_len(char *str);
int			ft_check_line(char *line);

void		ft_check_file(char *file);

//for create struct for count how many places
t_map		*ft_create_map(char *file);

//format
int			ft_check_line_quantity(char *line, char c);
int			ft_check_horizontal(t_map *map);
int			ft_check_vertical(t_map *map);

void		ft_check_format(t_map *map);

//create game and utils
mlx_texture_t		*ft_png_to_texture(char *path, t_game *game);
t_character			*ft_init_characters_images(t_game *game);
t_exit				*ft_init_exit_images(t_game *game);

t_game		*ft_create_game(t_map *map);


//GAME
//utils hook
int			ft_check_new_position(int x, int y, t_game *game);
void		ft_draw_moves(int new_x, int new_y, char *direction, t_game *game);
void		ft_close(t_game *game);
void		ft_close_x(void *game);
void		ft_key_hook(mlx_key_data_t key, void *game);

void		ft_init_game(t_game *game);

//error
void		ft_error(void);
void		ft_error_message(char *message);

//Error mixed with free
void		ft_error_free_map(t_map *map);
void		ft_error_free_game(t_game *game);
//If chracter struct fails, i need liberate the struct and game 
//and the same with exit
void		ft_error_character(t_character *character, t_game *game);
void		ft_error_exit(t_exit *exit, t_game *game);
//This is for custonthe message if the game fails
void		ft_free_game_message(t_game *game, char *message);

//finally free and for all
void		ft_free_struct_map(t_map *map);
void		ft_free_struct_game(t_game *game);

#endif
