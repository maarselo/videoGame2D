/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:35:12 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/10 14:36:00 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	ft_putstr_fd("\033[1;31mError\n", 1);
	exit(1);
}

void	ft_error_message(char *message)
{
	ft_putstr_fd("\033[1;31mError\033[0m\n", 1);
	ft_putstr_fd(message, 1);
	exit(1);
}
