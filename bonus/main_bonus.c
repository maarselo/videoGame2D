/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:30:32 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 14:30:33 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		return (1);
	ft_check_file(argv[1]);
	map = ft_create_map(argv[1]);
	ft_check_format(map, argv[1]);
	game = ft_create_game(map);
	ft_init_game(game);
	ft_free_struct_game(game);
}
