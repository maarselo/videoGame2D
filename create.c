/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:19:27 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 16:19:28 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_places	*ft_create_struct(void)
{
	t_places	*places;

	places = (t_places *)malloc(sizeof(t_places));
	places->empty = 0;
	places->wall = 0;
	places->collectable = 0;
	places->exit = 0;
	places->initiation = 0;
	return (places);
}
