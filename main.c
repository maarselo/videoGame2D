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
#include <stdio.h>

void	ft_print_map(char **map)
{
    int	i;
    int	j;

    if (!map)
        return;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            printf("%c", map[i][j]);
            j++;
        }
        printf("\n"); // Salto de línea al final de cada fila
        i++;
    }
}
int	main(int argc, char **argv)
{
	t_map	map;
	//t_places	*places;

	if (argc != 2)
		return (1);
	ft_check_entry_to_map(argv[1], &map);
	ft_print_map(map.map);
	ft_free(map);
}
