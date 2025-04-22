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
# include <stdlib.h> //malloc
# include <fcntl.h> //for open file
# include <limits.h> //int max
# include <unistd.h> //write
# include <stdio.h> //for test

typedef struct s_map
{
	int			rows;
	int			columns;
	int			collectionables;
	char		**map;
}				t_map;

//entry and utils
int			ft_check_len(char *str);
int			ft_check_line(char *line);

void		ft_check_file(char *file);

//for create struct for count how many places
t_map		*ft_create_map(char *file);

//format
void		ft_check_format(t_map *map);

//error
void		ft_error(void);
//free
void		ft_free_struct_map(t_map *map);
void		ft_free(t_map *map);

#endif
