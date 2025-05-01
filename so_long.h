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
# include "./Libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

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

typedef struct s_game
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*character;
	mlx_image_t	*collectionable;
	mlx_image_t	*exit;
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
mlx_texture_t	*ft_png_to_texture(char *path, t_game *game);

t_game		*ft_create_game(t_map *map);

//error
void		ft_error(void);
void		ft_error_message(char *message);
void		ft_error_message_free_map(t_map *map);
void		ft_error_message_free_game(t_game *game);

//free
void		ft_free_struct_map(t_map *map);
void		ft_free_struct_game(t_game *game);
void		ft_free(t_game *game);

#endif
