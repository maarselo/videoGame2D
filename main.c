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

#include "so_long.h"

void	print_map(t_map *map)
{
	int	i;

	if (!map || !map->map)
	{
		printf("El mapa no está inicializado.\n");
		return ;
	}
	i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*file;

	if (argc != 2)
		return (1);
	file = argv[1];
	ft_check_file(file);
	map = ft_create_map(file);
	ft_check_format(map);
	ft_free(map);
}
