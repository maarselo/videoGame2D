/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:29:41 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 16:29:43 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_struct_places(t_places *places)
{
	free(places);
}

void	ft_free(t_places *places)
{
	ft_free_struct_places(places);
}
