/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:26:53 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/22 14:58:56 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_so_long	*infos(void)
{
	static t_so_long	infos;

	return (&infos);
}

t_images	*img(void)
{
	static t_images	img;

	return (&img);
}

void	exit_message(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	//free memory
	exit(EXIT_FAILURE);
}
