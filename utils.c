/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:26:53 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/26 21:31:42 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_so_long(void)
{
	free_split(infos()->map);
}

void	exit_message(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	free_split(infos()->map);
	exit(EXIT_FAILURE);
}

void	game_over(char *message)
{
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	exit(EXIT_SUCCESS);
}
