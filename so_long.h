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

typedef struct s_places
{
	int		empty;
	int		wall;
	int		collectable;
	int		exit;
	int		initiation;
}	t_places;

//for cretae struct for count how many places
t_places	*ft_create_struct(void);

//entry and utilsutils
int			ft_check_len(char *str);

int			ft_check_entry(char *file);
//error
void		ft_error(void);
//free
void		ft_free(t_places *places);
#endif
